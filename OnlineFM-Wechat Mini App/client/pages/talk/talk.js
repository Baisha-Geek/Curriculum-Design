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
    talk: [],
    navigation1: "",
    navigation2: "none",
    active1: "active",
    active2: "unactive",
    limit: ""
  },

  onShow: function (e) {
    var that = this;
    if (app.globalData.userName === '') {
      that.setData({
        login: false,
        user: {
          name: ""
        }
      })
    }
    else {
      that.allTalks();
      that.setData({
        login: true,
        user: {
          name: getApp().globalData.userName
        }
      })
    }
  },
  newTalk: function (e) {
    wx.navigateTo({
      url: '../newTalk/newTalk',
    })
  },
  oneTalk: function (e) {
    var that = this;
    wx.navigateTo({
      url: '../oneTalk/oneTalk?talkname=' + e.currentTarget.dataset.name + '&talkid='+e.currentTarget.dataset.id+'',
    })
  },
  endOneTalk: function(e){
    var that=this;
    wx.request({
      url: config.service.endOneTalkUrl,
      method:'POST',
      header:{
        'Content-Type':'application/json'
      },
      data: { userName: getApp().globalData.userName, talkId: e.currentTarget.dataset.id, talkName: e.currentTarget.dataset.name, userId: getApp().globalData.id },
      success(res) {
        if (res.data.status === 0) {
          wx.showToast({
            title: '已结束群聊',
            icon: 'success',
            duration: 2000
          });
          that.allTalks();
        }
      }
    })
  },
  endTalks: function (e) {
    var that = this;
    that.setData({
      navigation1: "none",
      navigation2: "",
      active1: "unactive",
      active2: "active"
    });
    wx.request({
      url: config.service.getTalksUrl,
      method: 'POST',
      header: {
        'Content-Type': 'application/json'
      },
      //获取已结束的项目
      data: { userName: getApp().globalData.userName, userId:getApp().globalData.id,status: "1", logged: getApp().globalData.login },
      success(result) {
        if (result) {
          that.setData({
            talk: result.data.talkTable
          })
        }
      }
    })
  },
  allTalks: function (e) {
    var that = this;
    that.setData({
      navigation1: "",
      navigation2: "none",
      active1: "active",
      active2: "unactive"
    });
    // wx.navigateBack({
    //   url: '../index/index'
    // })
    wx.request({
      url: config.service.getTalksUrl,
      method: 'POST',
      header: {
        'Content-Type': 'application/json'
      },
      //获取未结束的群聊
      data: { userName: getApp().globalData.userName, userId:getApp().globalData.id,status: "0", logged: getApp().globalData.login },
      success(result) {
        if (result) {
          that.setData({
              talk: result.data.talkTable
          });
          var length=result.data.talkTable.length;
          for(var i=0;i<length;i++){
            if(that.data.talk[i].creatName===getApp().globalData.userName){
                that.data.talk[i].is_display="block";
            }
            else{
                that.data.talk[i].is_display="none";
            }
            that.setData({
              talk:that.data.talk
            })
          }
        }
      }
    });
  }
})
