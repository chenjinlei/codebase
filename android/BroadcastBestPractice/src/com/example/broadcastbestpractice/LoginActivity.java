package com.example.broadcastbestpractice;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends Activity implements OnClickListener {

	private EditText accountEdit;
	private EditText passwordEdit;
	private Button login;

	private SharedPreferences pref;
	private SharedPreferences.Editor editor;
	private CheckBox rememberPass;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.login);

		accountEdit = (EditText) findViewById(R.id.account);
		passwordEdit = (EditText) findViewById(R.id.password);
		login = (Button) findViewById(R.id.login);
		login.setOnClickListener(this);

		rememberPass = (CheckBox) findViewById(R.id.remember_pass);
		pref = PreferenceManager.getDefaultSharedPreferences(this);
		boolean isRemembered = pref.getBoolean("remember_password", false);

		if (isRemembered) {
			String account = pref.getString("account", "");
			String password = pref.getString("password", "");
			accountEdit.setText(account);
			passwordEdit.setText(password);
			rememberPass.setChecked(true);

		}

	}

	@Override
	public void onClick(View v) {
		switch (v.getId()) {
		case R.id.login:
			String account = accountEdit.getText().toString();
			String password = passwordEdit.getText().toString();
			if (account.equals("admin") && password.equals("123456")) {
				editor = pref.edit();
				if (rememberPass.isChecked()) {
					editor.putBoolean("remember_password", true);
					editor.putString("account", account);
					editor.putString("password", password);
				} else {
					editor.clear();
				}
				editor.commit();
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
