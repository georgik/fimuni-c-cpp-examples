//
//  main.m
//  hellomuni
//
//  Created by Juraj Michalek on 5/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        BOOL isItTrue = YES;
        NSString *who = @"FI MUNI";
        if (isItTrue) {
            NSLog(@"Hello, %@!", who);
        }
    }
    return 0;
}

