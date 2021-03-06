#pragma once
#include <list>
#include "XHChatroomManager.h"
#include "CConfigManager.h"
using namespace std;

// CChatroomDlg 对话框

class CChatroomDlg : public CDialogEx, public IChatroomManagerListener, public IChatroomGetListListener
{
	DECLARE_DYNAMIC(CChatroomDlg)

public:
	CChatroomDlg(CUserManager* pUserManager, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChatroomDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHATROOM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void getChatroomList();
	void resetChatroomList();
	void setConfig(CConfigManager* pConfig);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonChatroomSendMsg();
	afx_msg void OnBnClickedButtonCreateChatroom();
	afx_msg void OnNMClickListChatroomList(NMHDR *pNMHDR, LRESULT *pResult);	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnNMRClickListChatroomList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonDeleteChatroom();
public:
	/**
	 * 查询聊天室列表回调
	 */
	virtual int chatroomQueryAllListOK(list<ChatroomInfo>& listData);
	/**
	 * 聊天室成员数变化
	 * @param number
	 */
	virtual void onMembersUpdated(int number);

	/**
	 * 自己被踢出聊天室
	 */
	virtual void onSelfKicked();

	/**
	 * 自己被踢出聊天室
	 */
	virtual void onSelfMuted(int seconds);

	/**
	 * 聊天室已关闭
	 */
	virtual void onClosed();

	/**
	 * 收到消息
	 * @param message
	 */
	virtual void onReceivedMessage(CIMMessage* pMessage);

	/**
	 * 收到私信消息
	 * @param message
	 */
	virtual void onReceivePrivateMessage(CIMMessage* pMessage);


public:
	CUserManager* m_pUserManager;
	CConfigManager* m_pConfig;
	XHChatroomManager* m_pChatroomManager;
	CListCtrl m_ChatroomList;
	CListBox m_HistoryMsgListBox;
	CEdit m_SendMsgEdit;
	list<ChatroomInfo> mDatas;
	ChatroomInfo* m_pCurrentShow;
	
	CStatic m_ChatroomName;
	
	
};
