package com.intelli.qingfeng.app.util;

public interface HttpCallbackListener {
	
	void onFinish(String response);
	void onError(Exception e);

}
