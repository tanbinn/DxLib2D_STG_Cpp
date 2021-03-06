/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* IMAGE.cpp     																				　 */
/* 画像クラス 																					　 */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include <string>

//########## マクロ定義：画像のファイルパスと名前 ##########
#define MY_IMG_DIR_JIKI		R"(.\MY_IMG\JIKI\)"	//自機の画像ファイルの場所
#define MY_IMG_DIR_BACK		R"(.\MY_IMG\BACK\)"	//背景の画像ファイルの場所
#define MY_IMG_DIR_STAR		R"(.\MY_IMG\STAR\)"	//星の画像ファイルの場所

#define MY_IMG_NAME_JIKI_1	R"(jiki_1_mini.png)"		//自機１の名前
#define MY_IMG_NAME_JIKI_2	R"(jiki_2_mini.png)"		//自機２の名前

#define MY_IMG_NAME_BACK	R"(back.jpg)"				//背景の名前
#define MY_IMG_NAME_STAR	R"(star.png)"				//星の名前

//########## マクロ定義：エラーメッセージ##########
#define IMAGE_ERROR_TITLE "IMAGE_ERROR"					//エラータイトル
#define IMAGE_ERROR_MSG	"画像が読み込めませんでした"	//エラーメッセージ

//########## クラスの定義 ##########

class IMAGE
{
private:
	std::string FilePath;	//パス
	std::string FileName;	//名前

	int Handle;				//ハンドル

	int Width;				//幅
	int Height;				//高さ

	bool IsLoad;			//読み込めたか？

public:
	IMAGE(const char *,const char *);	//コンストラクタ
	virtual ~IMAGE();					//デストラクタ

	std::string GetFileName(void);	//名前を取得

	int GetWidth(void);				//幅を取得
	int GetHeight(void);			//高さを取得

	bool GetIsLoad(void);			//読み込めた？

	void Draw(int,int);				//画像を描画
};

