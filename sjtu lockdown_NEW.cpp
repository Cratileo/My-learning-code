//来玩这个贵交封闭化管理小游戏吧...
//程序暂时不释放内存，因为出现错误
//URL调用外部浏览器命令属实搞不懂，先搁置
#include<iostream>
#include<random>
#include<Windows.h>
#include<cstring>

std::random_device rd;
std::default_random_engine e(rd());
std::uniform_int_distribution<time_t> u(0, 3);
std::uniform_int_distribution<time_t> c(0, 1);
std::uniform_int_distribution<time_t> a(1, 7);

void student_free();         //半自由学生
void student_lock();        //2+5或七天学生
void student_outside();    //还在来的路上
void student_quarantined();//喜提转运
void cainiao();          //菜鸟驿站事件
void domitory();        //宿舍事件
void supermaket();     //西区教超事件
void henu();          //华师大事件
auto check();        //选择校验函数
void shuiyuan(int n);      //水源事件
void enter();
void happyend();

using std::cout;
using std::cin;

int main()
{
	using namespace std;
	cout << "欢迎游玩封闭化管理大冤种文游\n";
	cout << "在这个世界，你将扮演冤种学生或者……其中的幸运儿\n";
	cout << "角色是纯随机分配的，祝你好运\n";
	cout << "（这不和贵交的宿舍抽奖一个样吗）本游戏还在开发中……\n\n"
		<< "------------------------------------------------------------\n";
	cout << "游戏加载中";
	Sleep(800);
	for (int i = 0; i < 50; ++i)
	{
		cout << ">";
		Sleep(10);
	}
	cout << endl;
	int temp = u(e);
	if (temp == 0)
		student_free();
	else if (temp == 1)
		student_lock();
	else if (temp == 2)
		student_outside();
	else if (temp == 3)
		student_quarantined();
	else
	{
		cout << "出bug了，重开吧！\a\n"
			<< "错误代码：" << temp << endl;
		system("pause");
		return 0;
	}
	cout << "\n游戏结束，欢迎再来当冤种\n"
		 << "想看我们的背景介绍吗？  Y想/N不想\n";
	char* n = new char;
	cin >> n;
	_strlwr_s(n, strlen(n) + 1);
	while (strcmp(n, "y") && strcmp(n, "n"))
	{
		cout << "\n整点正经的活好伐，输认真点！\a";
		cin >> n;
		cin.clear();
	}
	if (!(strcmp(n, "y")))
	{
		cout << "《封闭化管理》是交通大学自主研发的一款全新封闭世界冒险游戏，游戏发生在一个被称作[闵行校区]的幻想世界，\n"
			<< "在这里被神选中的人将被授予[南洋北苑4-7天隔离]，导引新冠之力，你将扮演一位名为[冤种学生]的神秘角色，\n"
			<< "在自由的网课生活中邂逅性格各异、能力独特的同伴们，和他们一起做核酸，找回失散的密接\n"
			<< "——同时逐步发掘[人性化管理]的真相\n";
		system("pause");
	}
	else
	{
		cout << "少女折寿中……\n";
		Sleep(1500);
	}
	
	return 0;
}

auto check()
{
	char* n = new char;
	cin >> n;
	_strlwr_s(n, strlen(n) + 1);
	while (strcmp(n, "a") && strcmp(n, "b"))
	{
		cout << "\n输错了，重来！\a";
		cin >> n;
		cin.clear();
	}
	return n;
}

void student_free()
{

	cout << "挺幸运的，居然没被封楼\n";
	cout << "那接下来我要\n";
	system("pause");
	int temp = u(e);
	if (temp == 0)
	{
		cout << "去趟菜鸟驿站\n";
		cainiao();
	}
	else if (temp == 1)
	{
		cout << "还是在宿舍躺平比较好\n";
		domitory();
	}
	else if (temp == 2)
	{
		cout << "去南体教超囤点货\n";
		supermaket();
	}
	else if (temp == 3)
	{
		cout << "既然庙门开了那就去一趟华师吧（x\n";
		henu();
	}
	else
		cout << "出bug了，重开吧\a\n错误代码为"
		<< temp << std::endl;
}

void student_lock()
{
	cout << "淦，楼里有密接了";
	cout << "这下得坐七天牢了\n";
	cout << "网课，盒饭……";
	cout << "真tm不想上了啊\n";
	system("pause");
	cout << "\n-------------------1days after-------------------\n";
	if (u(e) != 1)
	{
		cout << "还好，你没阳,至少目前\n";
		cout << "现在你要:\nA)高强度水源对线\n";
		cout << "B)算了吧，累了\n你的选择是: ";
		auto input = check();     //使用check函数进行检测
		if (!(strcmp(input, "a")))
		{
			cout << "\nSir,this way";
			cout << "\n\a调用url功能暂时无法使用，将回到正常流程";
			Sleep(3 * 1000);
			//ShellExecute(NULL, "open", "https://shuiyuan.sjtu.edu.cn/", NULL, NULL, SW_SHOWNORMAL);//先不管这个了
			cout << "\n对线完了，即将回到正常流程\n\n";
			system("pause");
		}
		else
		{
			cout << "\n水源对线有啥意思啊，还是原神好玩捏\n";
		}
		//delete input;
		for (int i = 0; i < 6; ++i)
		{
			cout << "又一天过去了，今天你获得了免费的";
			if (i % 2 == 0)
			{
				cout << "水果和零食\n"
					<< "今天你们楼又被拉走了"<<u(e)<<"人\n";
			}
			else
				cout << "泡面和鸡排\n"
				<< "今天你们楼又被拉走了" << u(e) << "人\n";
			if (u(e)==3)
			{
				cout << "\n很不幸，你成为了密接（tmd）\n"
					<< "你思来想去，结合水源信息，应该是13号去主图自习导致的\n"
					<< "你说我干啥不好怎么就非得去图书馆呢（拍桌）\n"
					<< "------------------------------------------------------------\n";
				student_quarantined();
				return;
			}
			Sleep(600);
		}
		cout << "七天之后，终于坐牢结束，好在没有什么非闭环新增了\n"
			<< "但通过七天的封闭，你成功的……\n涨了10斤！\n艹\n";
		cout << "-----------------------结局：有惊无险-----------------------\n";
	}
	else
	{
		cout << "坏了，我成密接了\n";
		student_quarantined();
	}
}

void student_outside()
{
	cout << "现在你的位置在上海虹桥国际机场T2航站楼到达大厅\n";
	cout << "正准备转三次地铁前往闵大荒\n"
		<< "地铁上总归是有些无聊的，你决定";
	cout << "A)玩‘原神’       B)高强度刷水源\n";
	char* choice = check();
	if (!(strcmp(choice, "a")))
	{
		cout << "不愧是校友企业，闵大荒学子就该玩原神（什么暴论\n"
			<< "不知不觉，人已经到东川路站了，你找了一辆共享单车骑向拖鞋门";
		cout << "但今天门口充斥着怪异的味道，保险起见，你决定\n";
		cout << "A)管他的，干就是了   B)遇事不决刷水源\n";
		char* input = check();
		if (!(strcmp(input, "a")))
		{
			cout << "保安劝你先不要忙着进校，但你丝毫不理会\n"
				 << "肯定是吓唬人的，你这样想着\n"
				 <<"来到了寝室，室友告诉了你今早的重磅新闻，你有点后悔,只能希望自己真的没事\n";
			Sleep(800);
			if (c(e) == 0)
			{
				cout << "\n还好，是真的没事，至少现在不用封着，不是吗？\n";
				student_free();
			}
			else if (c(e) == 1)
			{
				cout << "艹，我是什么究极冤种，刚进来就封楼，还七天，艹\n";
				student_lock();
			}
		}
		else
		{
			shuiyuan(1);
			//delete input;
		}
	}
	else
	{
		shuiyuan(2);
		//delete choice;
	}
}

void student_quarantined()
{
	cout << "恭喜你，你是幸运之子，神抽中来你，决定让你去酒店隔离\n";
	cout << "而对于这一切，你没得选\n";
	cout << "雪上加霜的是，今晚台风就要登陆了……\n"
		<< "当然，这不是最坏的，更寄的是……\n\n\n"
		<< "门对面有家KFC，而今天……正好是星期四\n"
		<< "---------------------BAD END----------------------\n";
}

void cainiao()
{
	cout << "拆快递总是开心事，不是吗？\n";
	cout << "\n-------------------1days after-------------------\n";
	cout << "你开始看到了水源置顶帖，此时有点担心会不会被拉走\n";
	for (int i = 0; i < 7; ++i)
	{
		cout << "一天过去了...\n";
		if (c(e) == 0)
		{
			cout <<"第" <<i+1<< "天，今日无事\n\n";
		}
		else
		{
			cout << "该来的还是要来的……";
			student_quarantined();
			break;
		}
	}
}

void domitory()
{
	cout << "你决定留在寝室躺平睡觉\n";
	cout << "\n-------------------1days after-------------------\n";
	cout << "由于零食不够，你有点想出去买东西了";
	if (c(e) == 0)
	{
		cout << "但现在终究是有点危险，还是不出去了算了，反正基本食物也还多着呢\n";
		cout << "接着奏乐，接着舞！\n";
		cout << "\n-------------------7days after-------------------\n"
			<< "一周过去，你有惊无险的成为了不被封控的幸运儿\n";
	}
	else
	{
		cout << "说走就走，先买点可乐，再来点薯片……\n";
		cout << "去哪里买呢？\n";
		cout << "A)东区教超         B)三餐便利店\n";
		char* choice = check();
		if (!(strcmp(choice, "a")))
		{
			supermaket();
		}
		else
		{
			cout << "买了一堆快乐水，真快乐！\n";
			cout << "\n-------------------1days after-------------------\n";
			cout << "你在水源上看到了东区教超封闭的消息，不禁感叹运气真好\n";
		}
		//delete choice;
	}
}

void supermaket()
{
	cout << "东区教超不愧是东西多，啥都有\n";
	cout << "\n-------------------1days after-------------------\n";
	cout << "艹，我怎么成密接了\n";
	student_quarantined();
}

void henu()
{
	cout << "忍了一个中秋，你决定申一个多码合一去隔壁看看\n"
		<< "到庙门的时候，保安还让你快点走，你感觉有点奇怪\n"
		<< "出了校门后，你决定去水源上看看\n";
	cout << "\n---------------You are a lucky dog---------------\n"
		<< ">>>>>隐藏成就：Run！<<<<<\n";
}

void shuiyuan(int n)
{
	cout << "你打开了水源社区，想找点有用的帖子\n"
		<< "在置顶贴中发现了疫情在交大爆发的消息\n"
		<< "你认为：A)肯定是谣言，哈人     B)宁可信其有\n";
	char *choice = check();
	int temp = n;
	if (temp == 2)
	{
		if (!(strcmp(choice, "a")))
		{
			cout << "我就在上海，我怎么没感受到疫情爆发()\n"
				<< "一路过来，五号线也没什么异常嘛，还是玩玩近处的原神吧家人们\n"
				<< "------------------------------------------------------------\n";
			Sleep(500);
			cout << "不愧是校友企业，闵大荒学子就该玩原神（什么暴论\n"
				<< "不知不觉，人已经到东川路站了，你找了一辆共享单车骑向拖鞋门\n";
			cout << "但今天门口充斥着怪异的味道，保险起见，你决定\n"
				<< "A）选择相信水源消息，及时折返止损\n"
				<< "B)我就不信邪了，还能重返三月不成\n";
			auto choice_2 = check();
			if (!(strcmp(choice_2, "a")))
			{
				happyend();
			}
			else
				enter();
		}
		else
		{
			happyend();
		}

	}
	else
	{
		if (!(strcmp(choice, "a")))
		{
			enter();
		}
		else
		{
			happyend();
		}
	}
}

void enter()
{
	cout << "开学消息繁杂真假难辨，还是以官方为准\n"
		<< "这么想着，你进了学校\n";
	cout << "保安劝你先不要忙着进校，但你丝毫不理会\n"
		<< "肯定是吓唬人的，你这样想着\n"
		<< "来到了寝室，室友告诉了你今早的重磅新闻，你有点后悔,只能希望自己真的没事\n";
	Sleep(800);
	if (c(e) == 0)
	{
		cout << "\n还好，是真的没事，至少现在不用封着，不是吗？\n";
		student_free();
	}
	else if (c(e) == 1)
	{
		cout << "艹，我是什么究极冤种，刚进来就封楼，还七天，艹\n";
		student_lock();
	}
}

void happyend()
{
	cout << "你在闵大荒外面的酒店住了一晚，虽说200米有些痛，但还是观望一下好\n"
		<< "------------------------------------------------------------\n"
		<< "第二天，早上九点\n"
		<< "你从10小时的睡眠中醒来，稍作整理之后，再次打开了水源看看\n\n";
	cout << "\n---------------You are a lucky dog---------------\n"
		<< ">>>>>>>>>>隐藏成就：多刷水源有益健康<<<<<<<<<<\n";
}