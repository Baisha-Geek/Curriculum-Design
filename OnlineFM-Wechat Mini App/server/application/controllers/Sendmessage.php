<?php
/**
 * Created by PhpStorm.
 * User: 64980
 * Date: 2018/5/6
 * Time: 18:48
 */

defined('BASEPATH') OR exit('No direct script access allowed');

use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Sendmessage extends CI_Controller {
    public function index() {
        DB::getInstance();
        $raw = file_get_contents('php://input');
        $data = json_decode($raw,true);

        DB::insert('message',['head_owner'=>$data['head_owner'],'talkid'=>$data['talkId'],'kind'=>$data['kind'],
            'content'=>$data['content'],'time'=>$data['time'],'userid'=>$data['id'],'username'=>$data['username']]);
        $this->json([
            'status' => 0
        ]);
    }
}
