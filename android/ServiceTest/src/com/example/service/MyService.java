package com.example.service;

import com.example.servicetest.MainActivity;

import android.R;
import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Intent;
import android.os.Binder;
import android.os.IBinder;
import android.util.Log;

public class MyService extends Service {
	
	private static final String TAG = "MyService";
	private DownloadBinder mBinder = new DownloadBinder(); 

	@Override
	public IBinder onBind(Intent intent) {
		// TODO Auto-generated method stub
		return mBinder;
	}

	@SuppressWarnings("deprecation")
	@Override
	public void onCreate() {
		// TODO Auto-generated method stub
		super.onCreate();
		Notification notification = new Notification(R.drawable.ic_lock_idle_alarm,
				"Notification comes", System.currentTimeMillis());
		Intent notificationItent = new Intent(this, MainActivity.class);
		PendingIntent pendingIntent = PendingIntent.getActivity(this, 0, notificationItent, 0);
		notification.setLatestEventInfo(this, "This is title", "This is content", pendingIntent);
		this.startForeground(1, notification);
		Log.d(TAG, "onCreate executed");
	}

	@Override
	public int onStartCommand(Intent intent, int flags, int startId) {
		// TODO Auto-generated method stub
		new Thread(new Runnable() {

			@Override
			public void run() {
				// TODO Auto-generated method stub
				stopSelf();
			}}).start();
		Log.d(TAG, "onStartCommand executed");
		return super.onStartCommand(intent, flags, startId);
	}

	@Override
	public void onDestroy() {
		// TODO Auto-generated method stub
		super.onDestroy();
		Log.d(TAG, "onDestory executed");
	}

	public class DownloadBinder extends Binder {
		
		public void startDownload() {
			Log.d(TAG, "startDownload executed");
		}
		
		public int getProgress() {
			Log.d(TAG, "getProgress executed");
			return 0;
		}
	}
}
