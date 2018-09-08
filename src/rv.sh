#!/bin/bash
verilator `exec find . -type d | xargs printf -- '-y %s\n' | xargs echo` "$@"
