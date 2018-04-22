var qcloud = require('../../vendor/wafer2-client-sdk/index')
var config = require('../../config')
var util = require('../../utils/util.js')

const app = getApp();
Page({
  data: {
    login:false,
    user: {
      authority: 0,
      name: ""
    },
    project: [],
    navigation1: "",
    navigation2: "none",
    active1: "active",
    active2: "unactive",
    limit: "none"
  },
  onShow: function(e){
    var that=this;
    if (app.globalData.userName===''){
      that.setData({
        login:false,
        user:{
          name:""
        }
      })
    }
    else{
      wx.request({
        url: config.service.getProsUrl,
        method: 'POST',
        header: {
          'Content-Type': 'application/json'
        },
        data: { userName:getApp().globalData.userName,logged:getApp().globalData.login},
        success(result) {
          if (result) {
            that.setData({
              project: result.data.projectTable
            })
          }
        }
      })
      that.setData({
        login:true,
        user:{
          name: getApp().globalData.userName
        }
      })
    }
    console.log(that.data.login);
  },

  newPro: function (e) {
    wx.navigateTo({
      url: '../newPro/newPro',
    })
  },
  onePro: function (e) {
    var that=this;
    console.log(e.currentTarget.dataset.name);
    wx.navigateTo({
      url: '../onePro/onePro?proname='+e.currentTarget.dataset.name+'',
    })
  },
  endPros: function (e) {
    this.setData({
      navigation1: "none",
      navigation2: "",
      active1: "unacitve",
      active2: "active"
    })
  },
  allPros: function (e) {
    this.setData({
      navigation1: "",
      navigation2: "none",
      active1: "acitve",
      active2: "unactive"
    })
  }
})
