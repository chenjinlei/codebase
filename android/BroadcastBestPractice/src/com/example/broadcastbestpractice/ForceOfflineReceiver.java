package com.example.broadcastbestpractice;

import android.app.AlertDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.content.Intent;
import android.view.WindowManager;

public class ForceOfflineReceiver extends BroadcastReceiver implements OnClickListener {
	
	private Context context;

	@Override
	public void onReceive(Context context, Intent intent) {
		// force offline
		this.context = context;
		AlertDialog.Builder dialogBuilder = new AlertDialog.Builder(context);
		dialogBuilder.setTitle("Warning");
		dialogBuilder.setMessage("You are forced to be offline. Please try to login again.");
		dialogBuilder.setCancelable(false);
		
		dialogBuilder.setPositiveButton("OK", this);
		
		AlertDialog alertDialog = dialogBuilder.create();
		alertDialog.getWindow().setType(WindowManager.LayoutParams.TYPE_SYSTEM_ALERT);
		alertDialog.show();

	}

	@Override
	public void onClick(DialogInterface dialog, int which) {
		ActivityCollector.finishAll();
		
		Intent intent = new Intent(context, LoginActivity.class);
		intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);

		context.startActivity(intent);
		
	}

}
