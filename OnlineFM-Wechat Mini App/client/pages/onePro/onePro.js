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
    tempFilePaths:"",
    none_display:""
  },
  onLoad:function(data){
    this.setData({
      pro:{
        name:data.proname,
        id:data.proid
      }
    })
      wx.setNavigationBarTitle({ title: data.proname });
    this.getProject();
  },
    // 获取项目内容
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
          });
          if(result.data.projectInfo.file.length==0){
            that.setData({
                none_display:"block"
            })
          }
          else{
            that.setData({
                none_display:"none"
            });
            for (var i = 0; i < that.data.project.file.length; i++) {
                  that.data.imageList[i] = that.data.project.file[i].filePath;
              }
            if(that.data.project.status==="1"){
                  that.setData({
                      statusNavigation: "none"
                  });
                  for(var i=0;i<that.data.project.file.length;i++){
                      that.data.project.file[i].display="none";
                  }
                  that.setData({
                      project:that.data.project
                  })
              }
            else{
                  for(var i=0;i<that.data.project.file.length;i++){
                      if(that.data.project.file[i].uplodID==getApp().globalData.id){
                          that.data.project.file[i].display="block";
                          console.log(that.data.project.file[i].display)
                      }
                      else{
                          that.data.project.file[i].display="none";
                          console.log(that.data.project.file[i].display)
                      }
                      that.setData({
                          project:that.data.project
                      })
                  }
                  that.setData({
                      statusNavigation:"block"
                  })
              }
          }

        }
      }
    });
    this.setData({
      user: {
        name: getApp().globalData.userName
      }
    })
  },
    // 切换导航
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
    // 上传图片
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
    // 预览图片，借助微信的保存图片实现下载图片的效果
  previewImage:function(e){
    wx.previewImage({
      current: e.currentTarget.dataset.path,
      urls: this.data.imageList
    })
  },

  // 删除文件,只有对应的上传者可以删除
  delete:function(e){
    var that=this;
      wx.showModal({
          title: '提示',
          content: '是否删除文件'+e.currentTarget.dataset.name,
          success: function (res) {
              if (res.confirm) {
                  wx.request({
                      url: config.service.deleteFileUrl,
                      method: 'POST',
                      header: {
                          'Content-Type': 'application/json'
                      },
                      data: { fileId:e.currentTarget.dataset.id,uploadId:getApp().globalData.id},
                      success(result) {
                          if (result.data.status==0) {
                              wx.showToast({
                                  title: '删除成功',
                                  icon: 'success',
                                  duration: 2000
                              });
                              that.getProject();
                          }
                          else{
                              wx.showToast({
                                  title: result.data.message,
                                  duration:1000
                              })
                          }
                      }
                  })
              }
          }
      })

  }
})
