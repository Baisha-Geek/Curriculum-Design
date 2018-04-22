//my.js
var qcloud = require('../../vendor/wafer2-client-sdk/index')
var config = require('../../config')
var util = require('../../utils/util.js')
//获取应用实例
const app = getApp()
Page({
  data: {
    userInfo: {},
    logged: false,
    takeSession: false,
    requestResult: '',
    hasUserInfo: false,
    toast1Hidden:true,
    modalHidden: true,
    notice_str: '',
    user: {
      name: '',
      number: '',
      password: ''
    },
    login: false
  },

  login: function () {
    if (this.data.logged) return
    util.showBusy('正在登录')
    var that = this
    // 调用登录接口
    qcloud.login({
      success(result) {
        if (result) {
          util.showSuccess('登录成功')
          that.setData({
            userInfo: result,
            logged: true
          })
        } else {
          // 如果不是首次登录，不会返回用户信息，请求用户信息接口获取
          qcloud.request({
            url: config.service.requestUrl,
            login: true,
            success(result) {
              util.showSuccess('登录成功')
              that.setData({
                userInfo: result.data.data,
                logged: true
              });
            },
            fail(error) {
              util.showModel('请求失败', error)
              console.log('request fail', error)
            }
          })
        }
      },
      fail(error) {
        util.showModel('登录失败', error)
        console.log('登录失败', error)
      }
    })
  },

  // 切换是否带有登录态
  switchRequestMode: function (e) {
    this.setData({
      takeSession: e.detail.value
    })
    this.doRequest()
  },
  formSubmit: function (e) {
    var that = this;
    if(that.data.logged===false){
      wx.showModal({
        title: '提示',
        content: '请先登录微信',
        success: function (res) {
          if (res.confirm) {
            return;
          }
        }
      })
    }
    else if(e.detail.value.number===''||e.detail.value.password===''){
      wx.showModal({
        title: '提示',
        content: '输入不能有空，请检查输入',
        success: function (res) {
          if (res.confirm) {
            return;
          }
        }
      })
    }
    else{
      wx.request({
        url: config.service.bindUrl,
        method: 'POST',
        header: {
          'Content-Type': 'application/json'
        },
        data: { number: e.detail.value.number, password: e.detail.value.password, logged: that.data.logged },
        success: function (res) {
          console.log(res.data);
          if (res.data.status === 0){
            util.showSuccess('绑定成功');
            app.globalData.userName = res.data.data.name;
            app.globalData.login=true;
            that.setData({
              user: {
                name: res.data.data.name,
                number: res.data.data.number
              },
              login: true
            })
          }
          else if(res.data.status===-1){
            wx.showModal({
              title: '提示',
              content: '用户未登录微信',
              success: function (res) {
                if (res.confirm) {
                  return;
                }
              }
            })
          }
          else if(res.data.status===-2){
            wx.showModal({
              title: '提示',
              content: '用户不存在',
              success: function (res) {
                if (res.confirm) {
                  return;
                }
              }
            })
          }
          else if(res.data.status===-3){
            wx.showModal({
              title: '提示',
              content: '密码错误',
              success: function (res) {
                if (res.confirm) {
                  return;
                }
              }
            })
          }
        },
        fail(error) {
        }
      })
    } 
  },
  numberBind:function(){

  },
  relogin: function(){
    var that = this;
    app.globalData.login=false;
    app.globalData.userNamer='';
    that.setData({
      user: {
        name: '',
        number: '',
        password: ''
      },
      login: false
    })
  }
})
