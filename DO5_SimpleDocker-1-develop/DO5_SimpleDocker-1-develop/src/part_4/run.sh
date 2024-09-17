#!/bin/bash

gcc main.c -lfcgi -o main
spawn-fcgi -p 8080 ./main
service nginx start
nginx -s reload
/bin/bash
