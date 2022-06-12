#!/bin/sh

redis=/etc/redis/redis.conf
#change setting conf file
sed -i "s|bind 127.0.0.1|#bind 127.0.0.1|g" ${redis}
sed -i "s|maxmemory <bytes>|maxmemory 256mb|g" ${redis}
sed -i "s|maxmemory-policy noeviction|maxmemory-policy allkeys-lfu|g" ${redis}
sed -i "s|protected-mode yes|protected-mode no|g" ${redis}
# make the server run in the foreground
redis-server --protected-mode no


