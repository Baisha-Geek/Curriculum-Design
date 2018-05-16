var qcloud = require('../../vendor/wafer2-client-sdk/index')
var config = require('../../config')
var util = require('../../utils/util.js')

const app = getApp();
Page({
  data: {
    user: {
      name: ""
    }
  },
  onLoad: function (data) {
    this.setData({
      user: {
        name: getApp().globalData.userName
      }
    })
  },
})
