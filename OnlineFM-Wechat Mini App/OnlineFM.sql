/*
 Navicat Premium Data Transfer

 Source Server         : Localhost
 Source Server Type    : MySQL
 Source Server Version : 50717
 Source Host           : localhost
 Source Database       : cAuth

 Target Server Type    : MySQL
 Target Server Version : 50717
 File Encoding         : utf-8

 Date: 08/10/2017 22:22:52 PM
*/

SET NAMES utf8;
SET FOREIGN_KEY_CHECKS = 0;




-- -----------------------------------------------------------------------------------------------

--
-- 用户表的结构 `user`
--

DROP TABLE IF EXISTS `user`;
CREATE TABLE IF NOT EXISTS `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `userName` varchar(100) COLLATE utf8_bin NOT NULL,
  `userNumber` varchar(50) COLLATE utf8_bin NOT NULL,
  `userPwd` varchar(50) COLLATE utf8_bin NOT NULL,
  `root` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='用户表';

--
-- 转存表中的数据 `user`
--

INSERT INTO `user` (`id`, `userName`, `userNumber`, `userPwd`, `root`) VALUES
(1, '储向童', '0919160101', '123456', '1'),
(2, '唐崇鸾', '0919160102', '123456', '1'),
(3, '陈美妃', '0919160103', '123456', '1'),
(4, '胡学锋', '0919160104', '123456', '1'),
(5, '雷宇彤', '0919160105', '123456', '0'),
(6, '王帆', '0919160106', '123456', '0'),
(7, '姚伊扬', '0919160107', '123456', '0'),
(8, '陈陈', '0919160108', '123456', '0'),
(9, '代官伶', '0919160109', '123456', '0'),
(10, '李啸', '0919160110', '123456', '0'),
(11, '屈敏', '0919160111', '123456', '0'),
(12, '谢慧宣', '0919160112', '123456', '0'),
(13, '常耀星', '0919160113', '123456', '0'),
(14, '胡亚宸', '0919160114', '123456', '0'),
(15, '李妙姝', '0919160115', '123456', '0'),
(16, '梁志颖', '0919160116', '123456', '0'),
(17, '史博', '0919160117', '123456', '0'),
(18, '余亚伶', '0919160118', '123456', '0'),
(19, '陈思慧', '0919160119', '123456', '0'),
(20, '黄耀鹏', '0919160120', '123456', '0'),
(21, '黄耀鹏', '0919160121', '123456', '0'),
(22, '赵浩林', '0919160122', '123456', '0'),
(23, '张圣旭明', '0919160123', '123456', '0'),
(24, '展鹏元', '0919160124', '123456', '0'),
(25, '鲍雪培', '0919160125', '123456', '0'),
(26, '刘睿轩', '0919160126', '123456', '0'),
(27, '刘锦欢', '0919160127', '123456', '0'),
(28, '谢聪', '0919160128', '123456', '0');


-- --------------------------------------------------------------------------------

--
-- 项目表的结构 `project`
--

DROP TABLE IF EXISTS `project`;
CREATE TABLE IF NOT EXISTS `project` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `projectName` varchar(100) COLLATE utf8_bin NOT NULL,
  `creatName`  varchar(50) COLLATE utf8_bin NOT NULL,
  `status` int(11) NOT NULL DEFAULT '0',
  `userName`  varchar(50) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='项目组表';

--
-- 转存表中的数据 `project`
--

INSERT INTO `project` (`id`, `projectName`, `creatName`,`status`,`userName`) VALUES
(1, 'project1','储向童','1','储向童'),
(2, 'project1','储向童','1','唐崇鸾'),
(3, 'project1','储向童','1','陈美妃'),
(4, 'project1','储向童','1','胡学锋'),
(5, 'project1','储向童','1','雷宇彤'),
(6, 'project1','储向童','1','王帆'),

(7, 'project2','储向童','1','储向童'),
(8, 'project2','储向童','1','唐崇鸾'),
(9, 'project2','储向童','1','陈美妃'),
(10, 'project2','储向童','1','胡学锋'),

(11, 'project3','储向童','1','储向童'),
(12, 'project3','储向童','1','唐崇鸾'),
(13, 'project3','储向童','1','陈美妃'),

(14, 'project4','唐崇鸾','1','储向童'),
(15, 'project4','唐崇鸾','1','唐崇鸾'),
(16, 'project4','唐崇鸾','1','陈美妃'),

(17, 'project5','陈美妃','1','储向童'),
(18, 'project5','陈美妃','1','唐崇鸾'),
(19, 'project5','陈美妃','1','陈美妃');


-- -------------------------------------------------------------------------------------------

--
-- 项目表的结构 `file`
--

DROP TABLE IF EXISTS `file`;
CREATE TABLE IF NOT EXISTS `file` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `fileName` varchar(100) COLLATE utf8_bin NOT NULL,
  `filePath` varchar(120) COLLATE utf8_bin NOT NULL,
  `projectName` varchar(100) COLLATE utf8_bin NOT NULL,
  `uploadName` varchar(100) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='文件信息表';

