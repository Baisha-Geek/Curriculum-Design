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
    searchName:"",
    documentList: [],
    documentList2:[],
    imageList: [],
    navigation1: "",
    navigation2: "none",
    active1: "active", 
    active2: "unactive",
    limit: "none"
  },
  fileName: function (e) {
    this.setData({
      searchName: e.detail.value
    })
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
        data: { userId: getApp().globalData.id, logged: getApp().globalData.login,fileName:that.data.searchName },
        success(result) {
          if (result) {
            that.setData({
              documentList: result.data.documentTable,
              documentList2:result.data.documentTable2
            })
          }
        }
      })
      that.setData({
        login: true,
        user: {
          name: getApp().globalData.userName
        }
      });
      var i=0;
      for (i = 0; i < this.data.documentList.length; i++) {
        this.data.imageList[i] = this.data.documentList[i].filePath;
      }
      for(var j=0;j<this.data.documentList2.length;j++){
        this.data.imageList[i+j]=this.data.documentList2[j].filePath;
      }
    }
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
  previewImage: function (e) {
    wx.previewImage({
      current: e.currentTarget.dataset.path,
      urls: this.data.imageList
    })
  }
})