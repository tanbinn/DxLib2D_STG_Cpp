/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.cpp     																				   */
/* TAMAクラス																					   */

//########## ヘッダーファイル読み込み ##########
#include "TAMA.hpp"

//########## クラスの定義 ##########

//コンストラクタ
TAMA::TAMA()
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_DRAW_SPEED);

	this->SetInitInfo(0, 0, 0);	//初期設定

	return;
}

//コンストラクタ
TAMA::TAMA(int SetX, int SetY, int Number)
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_DRAW_SPEED);

	this->SetInitInfo(SetX, SetY, Number);	//初期設定

	this->collision = new COLLISION();			//当たり判定を作成
	this->collision->SetValue(this->X, this->Y, this->Width, this->Height);	//当たり判定を設定
	this->collision->SetIsDraw(true);			//当たり判定の範囲を描画する

	return;
}

//初期設定
void TAMA::SetInitInfo(int SetX, int SetY, int Number)
{
	this->SetSpeed(TAMA_MOVE_SPEED_SLOW);	//速さを設定

	this->SetX(SetX);		//位置を設定
	this->SetY(SetY);		//位置を設定

	this->SetNo(Number);	//番号を設定

	this->IsEnbled = true;	//弾を無効化

	return;
}

//弾のアニメーションを作成
void TAMA::SetAnime(const char *dir, const char *path, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed)
{
	this->Anime = new ANIMATION(
		dir,
		path,
		SplitNumALL,
		SpritNumX,
		SplitNumY,
		SplitWidth,
		SplitHeight,
		changeSpeed,
		true);	//弾を生成

	this->SetX(this->Anime->GetWidth());		//位置を設定
	this->SetY(this->GetCenterY());			//位置を設定

	this->IsEnbled = true;	//弾を無効化

	return;
}
//デストラクタ
TAMA::~TAMA()
{
	if (!this->Anime)	//emplace_backで呼ばれるときの対処
	{
		delete this->Anime;
	}

	return;
}

//弾を有効/無効にする
void TAMA::SetIsEnbled(bool set)
{
	this->IsEnbled = set; return;
}

//Noを取得
int  TAMA::GetNo(void)
{
	return this->No;
}

//Noを設定
void TAMA::SetNo(int Number)
{
	this->No = Number;
	return;
}

//速さを設定
void TAMA::SetSpeed(int sp)
{
	this->Speed = sp;
	return;
}

//速さを取得
int TAMA::GetSpeed(void)
{
	return this->Speed;
}

//X位置を取得
int TAMA::GetX(void)
{
	return this->X;
}

//Y位置を取得
int TAMA::GetY(void)
{
	return this->Y;
}

//X位置を設定
void TAMA::SetX(int SetX)
{
	this->X = SetX;
	return;
}

//Y位置を設定
void TAMA::SetY(int SetY)
{
	this->Y = SetY;
	return;
}

//幅を取得
void TAMA::GetWidth(int w)
{
	this->Width = w;
}

//幅を設定
int TAMA::SetWidth(void)
{
	return this->Width;
}

//高さを取得
void TAMA::GetHeight(int h)
{

}

//高さを設定
int TAMA::SetHeight(void)
{

}

//中心値を取得
int TAMA::GetCenterX(void)
{
	return (this->X + this->Anime->GetWidth()) / 2;
}

//中心値を取得
int TAMA::GetCenterY(void)
{
	return (this->Y + this->Anime->GetHeight()) / 2;
}

//操作
bool TAMA::Operation(void)
{
	this->SetX(this->X + this->Speed);	//弾の移動

	//弾が画面の中なら・・・
	if (this->GetX() >= 0 && this->GetX() <= GAME_WIDTH &&
		this->GetY() >= 0 && this->GetY() <= GAME_HEIGHT)
	{
		return true;	//弾の操作を継続
	}

	//弾が画面の外なら・・・
	return false;					//弾の操作終了
}

//画像を描画
void TAMA::Draw(void)
{
	if (this->IsEnbled == true)	//描画して良いなら
	{
		this->Anime->Draw(this->GetX(), this->GetY());
	}
}