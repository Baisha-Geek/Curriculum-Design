//app.js
var qcloud = require('./vendor/wafer2-client-sdk/index')
var config = require('./config')

App({
    globalData:{
      userName:'',
      authority:0,
      login:false
    },
    onLaunch: function () {
        qcloud.setLoginUrl(config.service.loginUrl)
    }
})