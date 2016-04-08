package com.example.broadcastbestpractice;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends Activity implements OnClickListener {

	private EditText accountEdit;
	private EditText passwordEdit;
	private Button login;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.login);

		accountEdit = (EditText) findViewById(R.id.account);
		passwordEdit = (EditText) findViewById(R.id.password);
		login = (Button) findViewById(R.id.login);

		login.setOnClickListener(this);
	}

	@Override
	public void onClick(View v) {
		switch (v.getId()) {
		case R.id.login:
			String account = accountEdit.getText().toString();
			String password = passwordEdit.getText().toString();
			if (account.equals("admin") && password.equals("123456")) {
				Intent intent = new Intent(this, MainActivity.class);
				startActivity(intent);
				finish();
			} else {
				Toast.makeText(this, "Wrong account name or wrong password", Toast.LENGTH_SHORT).show();
			}
			break;
		default:
			break;
		}

	}
}
