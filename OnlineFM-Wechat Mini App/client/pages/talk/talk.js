Page({
  data: {
    talk: [
      { kind: " ../../image/talk.png", name: "群聊一", id: "123" },
      { kind: "../../image/talk.png", name: "群聊二", id: "233" },
      { kind: "../../image/talk.png", name: "群聊三", id: "333" },
      { kind: "../../image/talk.png", name: "群聊四", id: "433" }
    ]
  },
  newTalk: function (e) {
    wx.navigateTo({
      url: '../newTalk/newTalk',
    })
  }
})
