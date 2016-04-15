package com.example.smstest;

import android.app.Activity;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.telephony.SmsMessage;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener {

	private TextView sender;
	private TextView content;
	
	private IntentFilter receiveFilter;
	private MessageReceiver messageReceiver;
	
	private TextView to;
	private EditText msgInput;
	private Button send;
	
	private IntentFilter sendFilter;
	private SendStatusReceiver sendStatusReceiver;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		sender = (TextView) this.findViewById(R.id.sender);
		content = (TextView) this.findViewById(R.id.content);
		
		to = (TextView) this.findViewById(R.id.to);
		msgInput = (EditText) this.findViewById(R.id.msg_input);
		send = (Button) this.findViewById(R.id.send);
		send.setOnClickListener(this);
		
		receiveFilter = new IntentFilter();
		receiveFilter.addAction("android.provider.Telephony.SMS_RECEIVED");
		messageReceiver = new MessageReceiver();
		this.registerReceiver(messageReceiver, receiveFilter);
		
		sendFilter = new IntentFilter();
		sendFilter.addAction("SENT_SMS_ACTION");
		sendStatusReceiver = new SendStatusReceiver();
		this.registerReceiver(sendStatusReceiver, sendFilter);
		
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
		this.unregisterReceiver(messageReceiver);
		this.unregisterReceiver(sendStatusReceiver);
		
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
	
	class MessageReceiver extends BroadcastReceiver {

		@Override
		public void onReceive(Context context, Intent intent) {
			Bundle bundle = intent.getExtras();
			Object[] pdus = (Object[] ) bundle.get("pdus");
			SmsMessage[] messages = new SmsMessage[pdus.length];
			for (int i = 0; i < messages.length; i ++) {
				messages[i] = SmsMessage.createFromPdu((byte[]) pdus[i]);
			}
			String address = messages[0].getOriginatingAddress();
			String fullMessage = "";
			for (SmsMessage message : messages) {
				fullMessage += message.getMessageBody();
			}
			sender.setText(address);
			content.setText(fullMessage);
			
			this.abortBroadcast();
			
		}
		
	}
	
	class SendStatusReceiver extends BroadcastReceiver {

		@Override
		public void onReceive(Context context, Intent intent) {
			if (this.getResultCode() == RESULT_OK) {
				Toast.makeText(context, "Send succeeded", Toast.LENGTH_LONG).show();
			} else {
				Toast.makeText(context, "Send failed", Toast.LENGTH_LONG).show();
			}
			
		}
		
	}

	@Override
	public void onClick(View v) {
		switch (v.getId()) {
		case R.id.send:
			SmsManager smsManager = SmsManager.getDefault();
			Intent sentIntent = new Intent("SENT_SMS_ACTION");
			PendingIntent pi = PendingIntent.getBroadcast(this, 0, sentIntent, 0);
			smsManager.sendTextMessage(to.getText().toString(), null, msgInput.getText().toString(), pi, null);
			break;
		}
		
	}
}
