#!/bin/sh

set -e

echo "=== DOCKER ENTRYPOINT ==="
COMMAND="$1"
case "$COMMAND" in
  run)
    echo "=== COMPILING AND RUNNING TSP PROBLEM  $*==="
    g++ -o main traveling_salesman.cpp
    ;;
  *)
    echo "=== RUNNING COMAND  $*==="
    sh -c "$*"
    ;;
esac