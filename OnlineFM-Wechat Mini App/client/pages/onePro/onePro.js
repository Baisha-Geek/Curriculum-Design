var qcloud = require('../../vendor/wafer2-client-sdk/index')
var config = require('../../config')
var util = require('../../utils/util.js')

const app = getApp();
Page({
  data: {
    user:{
      name:""
    },
    project:{},
    navigation1:"",
    navigation2:"none",
    active1:"active",
    active2:"unactive"
  },
  onLoad:function(data){
    var that=this;
    wx.request({
      url: config.service.oneProUrl,
      method: 'POST',
      header: {
        'Content-Type': 'application/json'
      },
      data: { userName: getApp().globalData.userNamer, proName: data.proname},
      success(result) {
        if (result) {
          that.setData({
            project: result.data.projectInfo
          })
        }
      }
    })
    this.setData({
      user:{
       name:getApp().globalData.userName
      }
    })
  },
  proFile:function(e){
    this.setData({
      navigation1: "none",
      navigation2: "",
      active1: "unactive",
      active2: "active"
    })
  },
  proIntro:function(e){
    this.setData({
      navigation1: "",
      navigation2: "none",
      active1: "active",
      active2: "unactive"
    })
  },
  upload:function(e){
    wx.chooseImage({
      success: function(res) {
        console.log("选择图片成功");
        var tempFilePaths = res.tempFilePaths;
        console.log(tempFilePaths);
        wx.uploadFile({
          url: config.service.uploadUrlUrl,
          filePath: tempFilePaths[0],
          name: 'img',
          header: {
            "Content-Type": "multipart/form-data",
            'accept': 'application/json',
          },  
          success:function(res){
            var data=res.data;
            console.log("img");
            console.log(data);
          },
          fail:function(res){
            console.log("fail");
          }
        })
      }
    })
  }
})
