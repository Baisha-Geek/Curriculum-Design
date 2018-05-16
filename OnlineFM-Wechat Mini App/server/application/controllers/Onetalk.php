<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Onetalk extends CI_Controller {
    public function index() {
        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');
        $data = json_decode($raw, true);


        $userId = $data['userId'];
        $talkId = $data['talkId'];
        $userName = $data['userName'];

//        $query="select talk.id, talk.talkName from talk inner join tmember on talk.id=tmember.pid where tmember.member='$userName' and talk.talkName='$proName'" ;
//        $rawSelectData = DB::rawselect($query);

        $message = array(
            array("id"=>1,"head_owner"=>"https://wx.qlogo.cn/mmopen/vi_32/Q0j4TwGTfTIeOqCQibNDH1NSFcdgAqaM3csqvDnbr5HZHtGj5IZyErJsic2diaEhMUvAyfdLRWJ6rzMMDvdYUX0gQ/132","kind"=>"img","imagePath"=>"https://wafer-1256206494.cos.ap-guangzhou.myqcloud.com/1273c5ac5a0b3d10664d3b436405ffbc-wx53804cfb523df61b.o6zAJs7Ld76AageQxSYagk9P_G2I.IK7FZPdulUfh39d1a97449458f3958323d1a174dfb9c.jpg","time"=>"18-05-15 00:08:25"),
            array("id"=>2,"head_owner"=>"https://wafer-1256206494.cos.ap-guangzhou.myqcloud.com/3fb5b0e758e966a1de7f0c46431b586a-wx53804cfb523df61b.o6zAJsxvCvZkwVWmY09SuAlyrHFw.52babe61c905ac5fa94cf305d062fd4d.png","kind"=>"text","content"=>"23333","time"=>"18-05-15 00:08:25"),
            array("id"=>3,"head_owner"=>"https://wafer-1256206494.cos.ap-guangzhou.myqcloud.com/0e248a2547e1a17f643096421bfb4d95-tmp_cbae133ed04f0c78b864d62dcc005a6079c073b8337cfaec.jpg","kind"=>"text","content"=>"23333","time"=>"18-05-15 00:08:25"),
            array("id"=>1,"head_owner"=>"https://wx.qlogo.cn/mmopen/vi_32/Q0j4TwGTfTIeOqCQibNDH1NSFcdgAqaM3csqvDnbr5HZHtGj5IZyErJsic2diaEhMUvAyfdLRWJ6rzMMDvdYUX0gQ/132","kind"=>"text","content"=>"张钏楠是个猴儿。233333，我要测试一下输很长的内容会怎么样","time"=>"18-05-15 00:08:25"),
            array("id"=>5,"head_owner"=>"https://wafer-1256206494.cos.ap-guangzhou.myqcloud.com/f63ecac94ab50c7331b81e808a4ab7a6-wx53804cfb523df61b.o6zAJsxvCvZkwVWmY09SuAlyrHFw.aylu5vYSmMJZb6c9d0f63b993d5b2e789f81d2b1f55f.png","kind"=>"text","content"=>"23333","time"=>"18-05-15 00:08:25"),
        );

        $rawSelectData = DB::row('talk',['id','talkName'],['id' => $talkId]);
        if($rawSelectData == NULL) {
            return $this->json([
                'status' => -1,
                'message' => '没有对应群聊',
                'talkInfo' => [], //返回空数组
            ]);
        }
        else {
            //若查询到信息， 应返回一个数组
//            $id=$rawSelectData[0]->id;
//            $name=$rawSelectData[0]->talkName;
            $member = DB::select('tmember', ['member'], ['tid' => $talkId]);
            if (DB::select('user', ['*'], ['id' => $userId, 'root' => 1]) == []) {
                $flag = false;
                foreach ($member as &$v) {
                    $v->userName = $v->member;
                    unset($v->member);
                    if ($v->userName == $userName) {
                        $flag = true;
                    }
                }
                //二次权限认证
                if ($flag == false) {
                    return $this->json([
                        'status' => -2,
                        'message' => '用户权限不足',
                        'talkInfo' => [],
                    ]);
                }
            }
            else {
                foreach ($member as &$v) {
                    $v->userName = $v->member;
                    unset($v->member);
                }
            }
            $fileInfo= DB::select('filetalk',['filePath','name','uplodName','uplodID'],['talkID'=>$talkId]);
            $message = DB::select('message',['head_owner','kind','content','time','userid'],['talkid'=>$talkId]);
            return $this->json([
                'status' => 0,
                'message' => '已获项目信息',
                "talkInfo" => [
                    'member' => $member,
                    'name' => $rawSelectData->talkName,
                    'file' => $fileInfo,
                ],
                "receiveMessage" =>$message
            ]);
        }
    }
}





