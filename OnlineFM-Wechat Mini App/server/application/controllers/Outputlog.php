<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use \QCloud_WeApp_SDK\Conf as Conf;
use \QCloud_WeApp_SDK\Cos\CosAPI as Cos;
use \QCloud_WeApp_SDK\Constants as Constants;
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Outputlog extends CI_Controller {
    public function index() {

        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');  //从前端读取数据
        $data = json_decode($raw, true);         
       
        //数据库读取消息
        $messageData = DB::select('message',['time','username','content'],['talkid' => $data['talkId']]);
        if($messageData != []) {
           
            //写入文件
            if($logfile = fopen("log.txt","w")){
               
                fwrite($logfile, json_encode($messageData, JSON_UNESCAPED_UNICODE));

                fclose($logfile);
            }    

            
            //上传日志文件并返回URL
            $cosClient = Cos::getInstance();
            $cosConfig = Conf::getCos();
            $bucketName = $cosConfig['fileBucket'];
            $folderName = $cosConfig['uploadFolder'];

            try {
                /**
                 * 列出 bucket 列表
                 * 检查要上传的 bucket 有没有创建
                 * 若没有则创建
                 */
                $bucketsDetail = $cosClient->listBuckets()->toArray()['Buckets'];
                $bucketNames = [];
                foreach ($bucketsDetail as $bucket) {
                    array_push($bucketNames, explode('-', $bucket['Name'])[0]);
                }

                // 若不存在 bucket 就创建 bucket
                if (count($bucketNames) === 0 || !in_array($bucketName, $bucketNames)) {
                    $cosClient->createBucket([
                        'Bucket' => $bucketName,
                        'ACL' => 'public-read'
                    ])->toArray();
                }

                // 上传文件
                $fileFolder = $folderName ? $folderName . '/' : '';
                $fileKey = $fileFolder . md5(mt_rand()) . '.txt';
                $uploadStatus = $cosClient->upload(
                    $bucketName,
                    $fileKey,
                    file_get_contents("log.txt")
                )->toArray();

                $this->json([
                    'status' => 0,
                    'message' => '成功返回URL',
                    'fileUrl' => $uploadStatus['ObjectURL'],
                ]);
            } catch (Exception $e) {
                $this->json([
                    'status' => 1,
                    'error' => $e->__toString()
                ]);
            }
        }
    }
}


