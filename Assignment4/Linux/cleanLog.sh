#!/bin/bash

sed -E \
  -e '/^#/d' \
  -e 's/[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}/XXXX-XXXX-XXXX-XXXX/g' \
  -e 's/[0-9]{16}/XXXX-XXXX-XXXX-XXXX/g' \
  -e 's/HTTP\/1\.0/HTTP\/1.1/g' \
  server_access.log > server_access.log.tmp && mv server_access.log.tmp server_access.log