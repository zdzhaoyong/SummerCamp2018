# 安装Docker后的一些准备工作

### 建立 docker 用户组

默认情况下，`docker` 命令会使用 [Unix socket](https://en.wikipedia.org/wiki/Unix_domain_socket) 与 Docker 引擎通讯。而只有 `root` 用户和 `docker` 组的用户才可以访问 Docker 引擎的 Unix socket。出于安全考虑，一般 Linux 系统上不会直接使用 `root` 用户。因此，更好地做法是将需要使用 `docker` 的用户加入 `docker` 用户组。

建立 `docker` 组：

```bash
$ sudo groupadd docker
```

将当前用户加入 `docker` 组：

```bash
$ sudo usermod -aG docker $USER
```

将用户加入组后需要log out并重新登录，这个时候运行docker时不用在前面添加sudo，如可直接运行`docker run hello-world`。

## 镜像加速器

国内访问 Docker Hub 有时会遇到困难，此时可以配置镜像加速器。Docker官方和国内很多云服务商都提供了加速器服务，例如：

* [Docker 官方提供的中国registry mirror](https://docs.docker.com/registry/recipes/mirror/#use-case-the-china-registry-mirror)
* [阿里云加速器](https://cr.console.aliyun.com/#/accelerator)
* [DaoCloud 加速器](https://www.daocloud.io/mirror#accelerator-doc)

注册用户并且申请加速器，会获得如 `https://jxus37ad.mirror.aliyuncs.com` 这样的地址。我们需要将其配置给 Docker 引擎。

### Ubuntu 14.04、Debian 7 Wheezy

对于使用 [upstart](http://upstart.ubuntu.com/) 的系统而言，编辑 `/etc/default/docker` 文件，在其中的 `DOCKER_OPTS` 中添加获得的加速器配置 `--registry-mirror=<加速器地址>`，如：

```bash
DOCKER_OPTS="--registry-mirror=https://jxus37ad.mirror.aliyuncs.com"
```

重新启动服务。

```bash
$ sudo service docker restart
```

### Ubuntu 16.04、Debian 8 Jessie、CentOS 7

对于使用 [systemd](https://www.freedesktop.org/wiki/Software/systemd/) 的系统，用 `systemctl enable docker` 启用服务后，编辑 `/etc/systemd/system/multi-user.target.wants/docker.service` 文件，找到 `ExecStart=` 这一行，在这行最后添加加速器地址 `--registry-mirror=<加速器地址>`，如：

```bash
ExecStart=/usr/bin/dockerd --registry-mirror=https://jxus37ad.mirror.aliyuncs.com
```

*注：对于 1.12 以前的版本，`dockerd` 换成 `docker daemon`。*

重新加载配置并且重新启动。

```bash
$ sudo systemctl daemon-reload
$ sudo systemctl restart docker
```

### Windows 10
对于使用 WINDOWS 10 的系统，在系统右下角托盘图标内右键菜单选择 `Settings`，打开配置窗口后左侧导航菜单选择 `Docker Daemon`。编辑窗口内的JSON串，填写如阿里云、DaoCloud之类的加速器地址，如：

```bash
{
  "registry-mirrors": [
    "https://sr5arhkn.mirror.aliyuncs.com",
    "http://14d216f4.m.daocloud.io"
  ],
  "insecure-registries": []
}
```
编辑完成，点击Apply保存后Docker服务会重新启动。

### macOS

对于macOS的用户，如果你使用的是**Docker for Mac**，那配置起来很简单。在任务栏点击应用图标 -> Perferences... -> Daemon -> Registry mirrors。在列表中添加云服务商提供的加速器地址即可。修改完成之后，点击`Apply & Restart`按钮，Docker就会重启并应用配置的镜像地址了。

### 检查加速器是否生效

Linux系统下配置完加速器需要检查是否生效，在命令行执行 `ps -ef | grep dockerd`，如果从结果中看到了配置的 `--registry-mirror` 参数说明配置成功。

```bash
$ sudo ps -ef | grep dockerd
root      5346     1  0 19:03 ?        00:00:00 /usr/bin/dockerd --registry-mirror=https://jxus37ad.mirror.aliyuncs.com
$
```
如果`Docker`版本大于1.13或17.05.0-ce，也可以
```bash
$ sudo docker info|grep "Registry Mirrors" -A 1
Registry Mirrors:
 https://registry.docker-cn.com/
```

##  修改Docker默认储存位置

docker的使用过程中会产生大量的文件，可使用`docker info`查看docker的基本信息。

```
Containers: 1
 Running: 0
 Paused: 0
 Stopped: 1
Images: 1
Server Version: 17.06.2-ce
Storage Driver: aufs
 Root Dir: /var/lib/docker/aufs
 Backing Filesystem: extfs
 Dirs: 3
 Dirperm1 Supported: true
Logging Driver: json-file
Cgroup Driver: cgroupfs
Plugins: 
 Volume: local
 Network: bridge host macvlan null overlay
 Log: awslogs fluentd gcplogs gelf journald json-file logentries splunk syslog
Swarm: inactive
Runtimes: runc
Default Runtime: runc
Init Binary: docker-init
containerd version: 6e23458c129b551d5c9871e5174f6b1b7f6d1170
runc version: 810190ceaa507aa2727d7ae6f4790c76ec150bd2
init version: 949e6fa
Security Options:
 apparmor
 seccomp
  Profile: default
Kernel Version: 4.4.0-21-generic
Operating System: Ubuntu 16.04 LTS
OSType: linux
Architecture: x86_64
CPUs: 4
Total Memory: 7.695GiB
Name: zhaoyong-TM1613
ID: B3ZW:3PST:A43E:XR6E:6KER:SG4C:XEHR:7ZIQ:SZ7Z:VBIK:CCAW:QP3W
Docker Root Dir: /var/lib/docker
Debug Mode (client): false
Debug Mode (server): false
Registry: https://index.docker.io/v1/
Experimental: false
Insecure Registries:
 127.0.0.0/8
Registry Mirrors:
 https://r1daq44j.mirror.aliyuncs.com/
Live Restore Enabled: false

WARNING: No swap limit support
```

可以看到, 其默认存放在`/var/lib/docker`目录, 下面我们将其转移到其他目录<my_new_location>.

* 停止 Docker 服务

```
sudo /etc/init.d/docker stop
```

* 将原来默认的/var/lib/docker备份一下，然后复制到别的位置并建立一个软链接

```
cd /var/lib
sudo mv docker <my_new_location>
sudo ln -s <my_new_location>/docker docker
```

* 启动 Docker 服务

```
sudo /etc/init.d/docker start
```

* 最后使用 docker info 查看更新结果:

```
Containers: 1
 Running: 0
 Paused: 0
 Stopped: 1
Images: 1
Server Version: 17.06.2-ce
Storage Driver: aufs
 Root Dir: /home/zhaoyong/Program/Software/docker/aufs
 Backing Filesystem: extfs
 Dirs: 3
 Dirperm1 Supported: true
Logging Driver: json-file
Cgroup Driver: cgroupfs
Plugins: 
 Volume: local
 Network: bridge host macvlan null overlay
 Log: awslogs fluentd gcplogs gelf journald json-file logentries splunk syslog
Swarm: inactive
Runtimes: runc
Default Runtime: runc
Init Binary: docker-init
containerd version: 6e23458c129b551d5c9871e5174f6b1b7f6d1170
runc version: 810190ceaa507aa2727d7ae6f4790c76ec150bd2
init version: 949e6fa
Security Options:
 apparmor
 seccomp
  Profile: default
Kernel Version: 4.4.0-21-generic
Operating System: Ubuntu 16.04 LTS
OSType: linux
Architecture: x86_64
CPUs: 4
Total Memory: 7.695GiB
Name: zhaoyong-TM1613
ID: B3ZW:3PST:A43E:XR6E:6KER:SG4C:XEHR:7ZIQ:SZ7Z:VBIK:CCAW:QP3W
Docker Root Dir: /home/zhaoyong/Program/Software/docker
Debug Mode (client): false
Debug Mode (server): false
Registry: https://index.docker.io/v1/
Experimental: false
Insecure Registries:
 127.0.0.0/8
Registry Mirrors:
 https://r1daq44j.mirror.aliyuncs.com/
Live Restore Enabled: false

WARNING: No swap limit support
```

可以看到，其根目录成功转移到了/home/zhaoyong/Program/Software/docker。

下一节： [获取镜像](pull.md)
