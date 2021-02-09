#!/bin/bash

BUILDDIR="docker_build"
PROJECT="edge-impulse-standalone"
COMMAND=$1

docker run -d -t --name eta \
		--rm \
		-v "$(pwd)":/app \
		--user "$(id -u):$(id -g)" \
		ei-eta-compute-build:1.2
docker exec eta /bin/sh -c 'if [ ! -d app/Applications/'$PROJECT'/'$BUILDDIR' ]; then mkdir app/Applications/'$PROJECT'/'$BUILDDIR'; make loadconfig CONFIG=../ei_ai_sensor_config; fi'
docker exec eta /bin/sh -c 'cd app/Applications/'$PROJECT'/'$BUILDDIR'; cmake ..; make '$COMMAND
docker kill eta

