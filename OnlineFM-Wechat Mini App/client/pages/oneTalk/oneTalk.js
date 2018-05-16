var qcloud = require('../../vendor/wafer2-client-sdk/index')
var config = require('../../config')
var util = require('../../utils/util.js')
var length;//收到的信息条数
const app = getApp();
Page({
  data: {
    name:"",
    id:"",
    user: {
      name: ""
    },
    path: "",
    imageList: [],
    talk:{},
    oldMessage:[],
    receiveMessage: [],
    newMessage:{
      content:"",
      time:""
    }, //用户新发的信息
    message_input:"",
    navigation1: "",
    navigation2: "none",
    active1: "active",
    active2: "unactive",
    showModal: false,
    filename: "",
    tempFilePaths: ""
  },
  onLoad: function (data) {
    var that = this;
    that.setData({
      name:data.talkname,
      id:data.talkid
    })
    that.getMessage();
    this.setData({
      user: {
        name: getApp().globalData.userName
      }
    });
    wx.setNavigationBarTitle({ title: that.data.name });  
  },
  // 切换导航
  talkFile: function (e) {
    for (var i = 0; i < this.data.talk.file.length; i++) {
      this.data.imageList[i] = this.data.project.file[i].filePath;
    }
    this.setData({
      navigation1: "none",
      navigation2: "",
      active1: "unactive",
      active2: "active"
    })
  },
  talkContent: function (e) {
    this.setData({
      navigation1: "",
      navigation2: "none",
      active1: "active",
      active2: "unactive"
    })
  },

  // 上传图片
  upload: function (e) {
    var that = this;
    wx.chooseImage({
      sizeType: ['original', 'compressed'],
      sourceType: ['album', 'camera'],
      success: function (res) {
        that.data.tempFilePaths = res.tempFilePaths;
        console.log(that.data.tempFilePaths);
        that.setData({
          showModal: true
        })
        that.confirm()
      }
    })
  },
  filename: function (e) {
    this.setData({
      filename: e.detail.value
    })
  },
  confirm() {
    if (this.data.filename !== "")
      this.onConfirm();
  },
  onConfirm: function () {
    var that = this;
    if (this.data.filename === "") {
      wx.showModal({
        title: '提示',
        content: '文件名不能有空，请检查输入',
        success: function (res) {
          if (res.confirm) {
            that.setData({
              filename: ""
            })
          }
        }
      })
    }
    else {
      this.hideModal();
      wx.showToast({
        title: "正在上传",
        icon: "loading",
        mask: true,
        duration: 5000
      });
      var creatTime = new Date();
      var time = that.dateFtt("yyyy-MM-dd hh:mm:ss", creatTime);
      // var uploadImgCount=0;
      // for(var i=0,h=tempFilePaths.length;i<h;i++){
      wx.uploadFile({
        url: config.service.uploadTalkUrl,
        filePath: that.data.tempFilePaths[0],
        name: "file",
        formData: {
          'head_owner': getApp().globalData.userInfo.avatarUrl,
          'talkID': that.data.talk.id,
          'kind':"image",
          'time':time,
          'uploadID': getApp().globalData.id,
          'username':getApp().globalData.userName,
          'fileName': encodeURI(that.data.filename)
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
          that.setData({
            tempFilePaths: "",
            filename: ""
          });
          that.getMessage();
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
  previewImage: function (e) {
    wx.previewImage({
      current: e.currentTarget.dataset.path,
      urls: this.data.imageList
    })
  },
  getMessage:function (e) {
    var that=this;
      wx.request({
          url: config.service.oneTalkUrl,
          method: 'POST',
          header: {
              'Content-Type': 'application/json'
          },
          data: { userName: getApp().globalData.userName, talkName: that.data.name, talkId: that.data.id, userId: getApp().globalData.id },
          success(result) {
              if (result) {
                  that.setData({
                      talk: result.data.talkInfo,
                      receiveMessage: result.data.receiveMessage,
                  });
                  for (var i = 0; i < result.data.receiveMessage.length;i++){
                    if (result.data.receiveMessage[i].userid==getApp().globalData.id){
                          that.data.receiveMessage[i].object = 0;
                      }
                      else{
                        that.data.receiveMessage[i].object = 1;
                      }
                      if (result.data.receiveMessage[i].kind=="text"){
                        that.data.receiveMessage[i].is_img = false;
                        that.data.receiveMessage[i].content = result.data.receiveMessage[i].content;
                      }
                      else{
                        that.data.receiveMessage[i].is_img = true;
                        that.data.receiveMessage[i].filePath = result.data.receiveMessage[i].imagePath;
                      }
                  }
                  that.setData({
                    receiveMessage: that.data.receiveMessage
                  });
                  that.bottom();
              };
              if(e){
                setTimeout(function(){
                  that.bottom();
                },500);
              }
          }
      });
      setTimeout(function () {
        if (that.data.receiveMessage.length != that.data.oldMessage.length){
          that.setData({
            oldMessage:that.data.receiveMessage
          })
        }
        //定时向服务器发送请求获取信息
        that.getMessage()
      }, 3000);
  },
  // 聊天
  bindChange: function (e) {
    this.setData({
      newMessage:{
        content:e.detail.value
      }
    })
  }, 
  add:function(e){
    var that=this;
    if(that.data.newMessage.content!==""){
      var creatTime=new Date();
      var time = that.dateFtt("yyyy-MM-dd hh:mm:ss",creatTime);
      wx.request({
        url: config.service.sendMessageUrl,
        method:'POST',
        header:{
          'Content-Type':'application/json'
        },
        data: { talkId: that.data.id, username:getApp().globalData.userName,id: getApp().globalData.id, head_owner: getApp().globalData.userInfo.avatarUrl,kind:"text",content:that.data.newMessage.content,time:time},
        success(res){
          if (res.data.status == 0) {
            var a = true;
            that.getMessage(a);
            that.setData({
              message_input: '',
              newMessage: {
                content: "",
                time: ""
              }
            })
          } else {
            wx.showToast({
              title: '网络错误,请稍后',
            })
          }  
        }
      })
    }
  },
  // 获取hei的id节点然后屏幕焦点调转到这个节点  
  bottom: function () {
    var query = wx.createSelectorQuery()
    query.select('#bottom').boundingClientRect()
    query.selectViewport().scrollOffset()
    query.exec(function (res) {
      wx.pageScrollTo({
        scrollTop: res[0].bottom  // #the-id节点的下边界坐标  
      })
      res[1].scrollTop // 显示区域的竖直滚动位置  
    })
  },  
  // 格式化时间
  dateFtt:function(fmt, date)   
  { 
    var o = {
      "y+": date.getFullYear(),                   //年份
      "M+": date.getMonth() + 1,                 //月份   
      "d+": date.getDate(),                    //日   
      "h+": date.getHours(),                   //小时   
      "m+": date.getMinutes(),                 //分   
      "s+": date.getSeconds(),                 //秒   
      "q+": Math.floor((date.getMonth() + 3) / 3), //季度   
      "S": date.getMilliseconds()             //毫秒   
    };   
    if(/(y +)/.test(fmt))
    fmt = fmt.replace(RegExp.$1, (date.getFullYear() + "").substr(4 - RegExp.$1.length));
    for (var k in o)
    if (new RegExp("(" + k + ")").test(fmt))
      fmt = fmt.replace(RegExp.$1, (RegExp.$1.length == 1) ? (o[k]) : (("00" + o[k]).substr(("" + o[k]).length)));
    return fmt;   
  } 
})
