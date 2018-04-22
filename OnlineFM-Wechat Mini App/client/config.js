/**
 * 小程序配置文件
 */

// 此处主机域名修改成腾讯云解决方案分配的域名
var host = 'https://2vnfxvwq.qcloud.la';

var config = {

    // 下面的地址配合云端 Demo 工作
    service: {
        host,

        // 登录地址，用于建立会话
        loginUrl: `${host}/weapp/login`,

        // 测试的请求地址，用于测试会话
        requestUrl: `${host}/weapp/user`,

        //绑定学号，获取对应的数据，类似于登录
        bindUrl: `${host}/weapp/binduser`,

        // 测试的信道服务地址
        tunnelUrl: `${host}/weapp/tunnel`,

        // 上传图片接口
        uploadUrl: `${host}/weapp/upload`,

        // 获取某个用户的项目列表
        getProsUrl: `${host}/weapp/projects`,

        // 搜索时获取所有文档
        searchUrl: `${host}/weapp/search`,

        // 获取一个项目的具体信息
        oneProUrl: `${host}/weapp/onepro`
    }
};

module.exports = config;