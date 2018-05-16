var qcloud = require('../../vendor/wafer2-client-sdk/index')
var config = require('../../config')
var util = require('../../utils/util.js')

const app = getApp(); 
Page({
  data: {
    user:{
      name:""
    },
    pro:{
      name:"",
      id:""
    },
    path:"",
    fileList:[],
    imageList:[],
    project:{},
    navigation1:"",
    navigation2:"none",
    statusNavigation:"block",
    active1:"active",
    active2:"unactive",
    showModal: false,
    fileName:"",
    tempFilePaths:""
  },
  onLoad:function(data){
    this.setData({
      pro:{
        name:data.proname,
        id:data.proid
      }
    })
    this.getProject();
  },
  getProject:function(){
    var that = this;
    wx.request({
      url: config.service.oneProUrl,
      method: 'POST',
      header: {
        'Content-Type': 'application/json'
      },
      data: { userName: getApp().globalData.userName, projectName: that.data.pro.name, proId: that.data.pro.id, userId: getApp().globalData.id },
      success(result) {
        if (result) {
          that.setData({
            project: result.data.projectInfo
          })
        }
      }
    });
    this.setData({
      user: {
        name: getApp().globalData.userName
      }
    })
  },
  proFile:function(e){
    for (var i = 0; i < this.data.project.file.length; i++) {
      this.data.imageList[i] = this.data.project.file[i].filePath;
    }
    if(this.data.project.status==="1"){
      this.setData({
        statusNavigation: "none"
      })
    }  
    else{
      this.setData({
        statusNavigation:"block"
      })
    }
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
    var that=this;
    wx.chooseImage({
      sizeType:['original','compressed'],
      sourceType:['album','camera'],
      success: function(res) {
        that.data.tempFilePaths = res.tempFilePaths;
        that.setData({
          showModal:true 
        })
        that.confirm()
      }
    })
  },
  fileName:function(e){
    this.setData({
      fileName:e.detail.value
    })
  },
  confirm(){
    if(this.data.fileName!=="")
      this.onConfirm();
  },
  onConfirm: function () {
    var that=this;
    if(this.data.fileName===""){
      wx.showModal({
        title: '提示',
        content: '文件名不能有空，请检查输入',
        success: function (res) {
          if (res.confirm) {
            that.setData({
              fileName:""
            })
          }
        }
      })
    }
    else{
      this.hideModal();
      wx.showToast({
        title: "正在上传",
        icon: "loading",
        mask: true,
        duration: 5000
      })
      console.log(that.data.project.proid)
      // var uploadImgCount=0;
      // for(var i=0,h=tempFilePaths.length;i<h;i++){
      wx.uploadFile({
        url: config.service.uploadUrl,
        filePath: that.data.tempFilePaths[0],
        name: "file",
        formData: {
          'projectId': that.data.project.proid,
          'uplodName': getApp().globalData.userName,
          'uplodId':getApp().globalData.id,
          'fileName': that.data.fileName
        },
        header: {
          "Content-Type": "multipart/form-data",
          'accept': 'application/json',
        },
        success: function (res) {
          wx.showToast({
            title: '上传成功',
            icon: "success",
            duration: 1000
          });
          that.getProject();
          that.setData({
            tempFilePaths:"",
            fileName:""
          })
        },
        fail: function (res) {
          wx.showModal({
            title: '错误提示',
            content: '上传图片失败',
            showCancel: false,
            success: function (res) { }
          })
        }
      })
    }
  },
  hideModal: function () {
    this.setData({
      showModal: false
    });
  },
  previewImage:function(e){
    wx.previewImage({
      current: e.currentTarget.dataset.path,
      urls: this.data.imageList
    })
  }
})
