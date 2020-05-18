#!/bin/sh

set -e

echo "=== DOCKER ENTRYPOINT ==="
COMMAND="$1"
case "$COMMAND" in
  *)
    echo "=== RUNNING COMAND  $*==="
    sh -c "$*"
    ;;
esac