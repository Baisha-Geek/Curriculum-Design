var qcloud = require('../../vendor/wafer2-client-sdk/index')
var config = require('../../config')
var util = require('../../utils/util.js')

// pages/newPro/newPro.js
const app = getApp();

Page({
  data: {
    showModal: false,
    choosen: [],
    name: "",
    addmember: [],
    member: [],
  },
  onLoad: function () {
    var that = this;
    wx.request({
      url: config.service.getMemberUrl,
      method: "GET",
      header: { 'Content-Type': 'application/json' },
      success: function (res) {
        if (res) {
          that.setData({
            member: res.data.member
          })
        }
      }
    })
  },
  enterName: function (e) {
    this.setData({
      name: e.detail.value
    })
  },
  addMember: function () {
    this.setData({
      showModal: true
    })
  },
  /**
    * 弹出框蒙层截断touchmove事件
    */
  preventTouchMove: function () {
  },
  /**
   * 隐藏模态对话框
   */
  hideModal: function () {
    this.setData({
      showModal: false
    });
  },
  /**
   * 对话框取消按钮点击事件
   */
  onCancel: function () {
    this.hideModal();
  },
  /**
   * 对话框确认按钮点击事件
   */
  checkboxChange: function (e) {
    var arr = [];
    arr = e.detail.value;
    this.setData({
      choosen: arr
    });
  },
  onConfirm: function () {
    this.setData({
      addmember: this.data.choosen
    })
    this.hideModal();
  },
  // 确认创建项目
  create: function () {
    var that = this;
    if (that.data.name === "") {
      wx.showToast({
        title: '请输入群聊名称',
        icon: 'none',
        duration: 2000
      })
    }
    else if (that.data.addmember.length === 0) {
      wx.showToast({
        title: '请选择群聊成员',
        icon: 'none',
        duration: 2000
      })
    }
    else {
      wx.request({
        url: config.service.newTalkUrl,
        method: "POST",
        header: { 'Content-Type': 'application/json' },
        data: { creatName: getApp().globalData.userName, talkName: that.data.name, member: that.data.addmember},
        success: function (res) {
          if (res) {
            wx.showModal({
              title: '提示',
              content: '创建群聊成功',
              success: function (res) {
                if (res.confirm) {
                  wx.navigateBack({
                    url: '../talk/talk',
                  })
                }
              }
            })
          }
        }
      })
    }
  }
})