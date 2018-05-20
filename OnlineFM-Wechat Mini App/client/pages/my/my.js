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
      password: '',
    },
    change:{
      oldpwd:"",
      newpwd:""
    },
    reset:false,
    login: false,
    canIUse: wx.canIUse('button.open-type.getUserInfo'),
  },
  onLoad:function(){
    if (app.globalData.userInfo) {
      this.setData({
        userInfo: app.globalData.userInfo,
        hasUserInfo: true,
        logged:true
      })
    } else if (this.data.canIUse) {
      // 由于 getUserInfo 是网络请求，可能会在 Page.onLoad 之后才返回
      // 所以此处加入 callback 以防止这种情况
      app.userInfoReadyCallback = res => {
        this.setData({
          userInfo: res.userInfo,
          hasUserInfo: true,
          logged:true
        })
      }
    } else {
      // 在没有 open-type=getUserInfo 版本的兼容处理
      wx.getUserInfo({
        success: res => {
          app.globalData.userInfo = res.userInfo
          this.setData({
            userInfo: res.userInfo,
            hasUserInfo: true,
            logged: true
          })
        }
      })
    }
  },
  getUserInfo: function (e) {
    console.log(e)
    app.globalData.userInfo = e.detail.userInfo
    this.setData({
      userInfo: e.detail.userInfo,
      hasUserInfo: true,
      logged:true
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
            app.globalData.authority=res.data.data.authority;
            app.globalData.id=res.data.data.id;
            that.setData({
              user: {
                name: res.data.data.name,
                number: res.data.data.number,
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
  resetsubmit:function (e) {
    var that=this;
    if(e.detail.value.oldpwd===""||e.detail.value.newpwd===""){
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
          url:config.service.updatePwdUrl,
          method:'POST',
          header: {
              'Content-Type': 'application/json'
          },
          data:{ logged:true,number:that.data.user.number,passwordfirst:e.detail.value.oldpwd,passwordsecond:e.detail.value.newpwd},
          success:function (res) {
              if (res.data.status===0){
                  util.showSuccess('修改成功');
                  that.setData({
                      user: {
                          name: getApp().globalData.userName,
                          number: that.data.user.number,
                      },
                      login: true,
                      reset:false
                  })
              }
              else{
                wx.showModal({
                  title: '提示',
                  content: res.data.message,
                  success: function (res) {
                    if (res.confirm) {
                      return;
                    }
                  }
                })
              }
          }
      })
    }
  },
  cancelReset:function () {
       this.setData({
           reset:false
       })
  },

  resetpwd:function () {
    var that=this;
    that.setData({
        change:{
            oldpwd:"",
            newpwd:""
        },
        reset:true
    })
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
