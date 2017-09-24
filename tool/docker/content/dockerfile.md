# Dockerfile

## Dockerfile介绍

关于Dockerfile的介绍和使用方法，建议先从以下资料中稍做了解：

* [使用Dockerfile来创建镜像](build.md)
* [Docker Practice](https://github.com/yeasy/docker_practice/blob/master/SUMMARY.md)

然后，本节将主要介绍如何通过Dockerfile来构建前一节的qtcreator镜像。

## 使用Dockerfile构建qtcreator镜像

目录SummerCamp2018/tool/docker/dockfiles/qtcreator展示了一个Dockerfile，描述了如何构建前面的qtcreator镜像。

* 首先创建空文件夹qtcreator, 在里面创建文件Dockerfile并在其中输入以下内容：

```
FROM ubuntu:16.04

MAINTAINER zd5945@125.com

RUN apt update \
    && apt install -y build-essential qtcreator libqt4-dev
    && rm -rf /var/lib/apt/lists/*
```

* 使用docker build命令自动构建镜像：

```
$docker build --network host -t qtcreator1 .
```

其中`--network host`指定网络类型，`-t qtcreator1`制定目标镜像名字。

* 我们可以使用上一节的方法把qtcreator1镜像作为应用程序打开
```
xhost +;docker run -d --rm --net=host --privileged -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v /home:/home qtcreator1 qtcreator
```

其中`-d`是在后台运行容器并返回容器ID，通过'docker log <container_id>'可以查看其输出。


* 为了使用方便，可以将下述代码添加到`~/.bashrc`中：

```
qtcreator()
{
xhost +;
docker run -d --rm --net=host --privileged -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v /home:/home qtcreator1 qtcreator $1
}
```
这样之后只需要直接使用qtcreator命令即可运行程序。


## 下一节[操作仓库](push.md)
