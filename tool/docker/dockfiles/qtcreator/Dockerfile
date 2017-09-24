FROM ubuntu:16.04

MAINTAINER zd5945@125.com

#COPY sources.list /etc/apt/sources.list

RUN apt update \
    && apt install -y build-essential qtcreator libqt4-dev
    && rm -rf /var/lib/apt/lists/*
