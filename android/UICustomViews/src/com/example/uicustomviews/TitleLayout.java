package com.example.uicustomviews;

import android.app.Activity;
import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Toast;
import android.view.View.OnClickListener;

public class TitleLayout extends LinearLayout implements OnClickListener {

	public TitleLayout(Context context, AttributeSet attrs) {
		super(context, attrs);
		LayoutInflater.from(context).inflate(R.layout.title, this);

		Button back = (Button) findViewById(R.id.title_back);
		Button edit = (Button) findViewById(R.id.title_edit);

		back.setOnClickListener(this);
		edit.setOnClickListener(this);
	}

	@Override
	public void onClick(View v) {
		switch (v.getId()) {
		case R.id.title_back:
			((Activity) getContext()).finish();
			break;
		case R.id.title_edit:
			Toast.makeText(getContext(), "You clicked Edit button", Toast.LENGTH_SHORT).show();
			break;
		default:
			break;
		}

	}

}
