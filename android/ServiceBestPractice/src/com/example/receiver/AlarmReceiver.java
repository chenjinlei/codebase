package com.example.receiver;

import com.example.service.LongRunningService;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class AlarmReceiver extends BroadcastReceiver {

	@Override
	public void onReceive(Context context, Intent intent) {
		// TODO Auto-generated method stub
		Intent i = new Intent(context, LongRunningService.class);
		context.startActivity(i);
		
	}

}
