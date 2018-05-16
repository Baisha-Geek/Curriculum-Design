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
    is_display:"",
    project: [],
    navigation1: "",
    navigation2: "none",
    active1: "active",
    active2: "unactive",
    limit: "",
    none_display:""
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
      that.allPros();
      if (app.globalData.authority === "0"){
        that.setData({
          is_display: "none"
        })
      }
      else{
        that.setData({
          is_display: "block"
        })
      }
      that.setData({
        login: true,
        user: {
          name: getApp().globalData.userName
        }
      })
    }
  },

  newPro: function (e) {
    wx.navigateTo({
      url: '../newPro/newPro',
    })
  },
  onePro: function (e) {
    var that=this;
    wx.navigateTo({
      url: '../onePro/onePro?proid='+e.currentTarget.dataset.id+'&proname='+e.currentTarget.dataset.name+'',
    })
  },
  endOnePro:function(e){
    var that=this;
    wx.request({
      url: config.service.endOneProUrl,
      method:'POST',
      header:{
        'Content-Type':'application/json'
      },
      data: { userName: getApp().globalData.userName, proId: e.currentTarget.dataset.id,projectName:e.currentTarget.dataset.name,userId:getApp().globalData.id},
      success(res){
        if(res.data.status===0){
          wx.showToast({
            title: '已结束项目',
            icon: 'success',
            duration: 2000
          });
          that.allPros();
        }
      }
    })

  },
  endPros: function (e) {
    var that=this;
    that.setData({
      navigation1: "none",
      navigation2: "",
      active1: "unactive",
      active2: "active"
    });
    wx.request({
      url: config.service.getProsUrl,
      method: 'POST',
      header: {
        'Content-Type': 'application/json'
      },
      //获取已结束的项目
      data: { userName: getApp().globalData.userName, userId: getApp().globalData.id, status:"1",logged: getApp().globalData.login },
      success(result) {
        if (result) {
          that.setData({
            project: result.data.projectTable
          })
        }
      }
    })
  },
  allPros: function (e) {
    var that=this;
    that.setData({
      navigation1: "",
      navigation2: "none",
      active1: "active",
      active2: "unactive"
    });
    wx.request({
      url: config.service.getProsUrl,
      method: 'POST',
      header: {
        'Content-Type': 'application/json'
      },
      //获取未结束的项目
      data: { userName: getApp().globalData.userName,userId:getApp().globalData.id, status: "0", logged: getApp().globalData.login },
      success(result) { 
        if (result) {
          that.setData({
            project: result.data.projectTable
          });
          if(that.data.project.length===0){
            that.setData({
              none_display:"block"
            })
          }
          else{
            that.setData({
              none_display:"none"
            })
          }
        }
      }
    });
  }
})
