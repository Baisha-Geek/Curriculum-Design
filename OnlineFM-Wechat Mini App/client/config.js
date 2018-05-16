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

        // 测试的信道服务地址
        tunnelUrl: `${host}/weapp/tunnel`,

        // 登录部分
        
        //绑定学号，获取对应的数据，类似于登录
        bindUrl: `${host}/weapp/binduser`,

        // 项目接口

        // 获取某个用户的项目列表
        getProsUrl: `${host}/weapp/projects`,

        // 获取一个项目的具体信息
        oneProUrl: `${host}/weapp/onepro`,

        //结束项目
        endOneProUrl: `${host}/weapp/endpro`,

        //创建项目
        newProUrl: `${host}/weapp/newpro`,

        // 群聊接口

        // 获取某个用户的群聊列表
        getTalksUrl: `${host}/weapp/talks`,

        // 获取一个群聊的具体信息
        oneTalkUrl: `${host}/weapp/onetalk`,

        // 发送信息
        sendMessageUrl: `${host}/weapp/sendmessage`,

        //结束群聊
        endOneTalkUrl: `${host}/weapp/endtalk`,

        //创建群聊
        newTalkUrl: `${host}/weapp/newtalk`,
        
        // 公共接口

        // 上传图片接口
        uploadUrl: `${host}/weapp/upload`,

        // 上传图片接口（群聊上传）
        uploadTalkUrl: `${host}/weapp/uploadtalk`,

        // 创建项目和群聊时获取成员的名字
        getMemberUrl: `${host}/weapp/getmember`,
        
        // 搜索接口

        // 搜索时获取所有文档
        searchUrl: `${host}/weapp/search`,    
    }
};

module.exports = config;