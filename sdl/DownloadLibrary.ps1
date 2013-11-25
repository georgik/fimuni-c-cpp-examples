Write-Host("Downloading library")
$workingPath = (Get-Location).path
$clnt = new-object System.Net.WebClient
$url = "http://libsdl.org/release/SDL2-devel-2.0.1-VC.zip"
$file = $workingPath + "\SDL2-devel-2.0.1-VC.zip"
$clnt.DownloadFile($url,$file)

Write-Host("Unzip the file to local directory")
$shell_app=new-object -com shell.application 
$zip_file = $shell_app.namespace($file) 
$destination = $shell_app.namespace($workingPath) 
$destination.Copyhere($zip_file.items())

Write-Host("Done")
