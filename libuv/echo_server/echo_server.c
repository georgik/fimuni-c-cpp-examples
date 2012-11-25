#include <uv.h>
#include <stdio.h>

uv_loop_t *loop;

uv_buf_t alloc_buffer(uv_handle_t *handle, size_t suggested_size) {
    return uv_buf_init((char*) malloc(suggested_size), suggested_size);
}

static void close_cb(uv_handle_t* handle) {
  printf("Connection closed\n");
}

void echo_read(uv_stream_t* tcp, ssize_t nread, uv_buf_t buf) {
  uv_err_t err = uv_last_error(uv_default_loop());

  if (nread > 0) {
	  printf("%.*s", nread, buf.base);
  } else if (nread < 0) {
    if (err.code == UV_EOF) {
      uv_close((uv_handle_t*)tcp, close_cb);
    }
  }
}

void on_new_connection(uv_stream_t *server, int status) {
	uv_tcp_t *client;
    if (status == -1) {
        // error!
        return;
    }

    client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
    uv_tcp_init(loop, client);
    if (uv_accept(server, (uv_stream_t*) client) == 0) {
        uv_read_start((uv_stream_t*) client, alloc_buffer, echo_read);
    }
    else {
        uv_close((uv_handle_t*) client, NULL);
    }
}

int main() {

    uv_tcp_t server;
	int r;
	struct sockaddr_in bind_addr;
	loop = uv_default_loop();
    uv_tcp_init(loop, &server);

    bind_addr = uv_ip4_addr("0.0.0.0", 7000);
    uv_tcp_bind(&server, bind_addr);
    r = uv_listen((uv_stream_t*) &server, 128, on_new_connection);
    if (r) {
        fprintf(stderr, "Listen error %s\n", uv_err_name(uv_last_error(loop)));
        return 1;
    }
    return uv_run(loop);
}