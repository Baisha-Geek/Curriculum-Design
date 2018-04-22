var qcloud = require('../../vendor/wafer2-client-sdk/index')
var config = require('../../config')
var util = require('../../utils/util.js')

const app = getApp();

Page({
  data: {
    login: false,
    user: {
      authority: 0,
      name: ""
    },
    documentList: [],
    navigation1: "",
    navigation2: "none",
    active1: "active",
    active2: "unactive",
    limit: "none"
  },
  search:function(e){
    var that=this;
    if (app.globalData.userName === '') {
      that.setData({
        login: false,
        user: {
          name: "",
          authority:0
        }
      })
    }
    else {
      wx.request({
        url: config.service.searchUrl,
        method: 'POST',
        header: {
          'Content-Type': 'application/json'
        },
        data: { userName: getApp().globalData.userName, logged: getApp().globalData.login },
        success(result) {
          if (result) {
            that.setData({
              documentList: result.data.documentTable
            })
          }
          console.log(result.data.documentTable);
        }
      })
      that.setData({
        login: true,
        user: {
          name: getApp().globalData.userName
        }
      })
    }
    console.log(that.data.login);
  },
  onShow: function (e) {
  },

  onShow: function (e) {
    if (app.globalData.userName === '') {
      this.setData({
        login: false,
        user: {
          name: ""
        }
      })
    }
    else {
      this.setData({
        login: true,
        user: {
          name: getApp().globalData.userName
        }
      })
    }
    console.log(this.data.login);
  },
})