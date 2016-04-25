package com.intelli.qingfeng.util;

public interface HttpCallbackListener {
	
	void onFinish(String response);
	void onError(Exception e);

}
