package com.example.providertest;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener {

	private String newId;
	private static final String TAG = "MainActivity";

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		Button addData = (Button) this.findViewById(R.id.add_data);
		Button queryData = (Button) this.findViewById(R.id.query_data);
		Button updateData = (Button) this.findViewById(R.id.update_data);
		Button deleteData = (Button) this.findViewById(R.id.delete_data);
		addData.setOnClickListener(this);
		queryData.setOnClickListener(this);
		updateData.setOnClickListener(this);
		deleteData.setOnClickListener(this);

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

	@Override
	public void onClick(View v) {

		switch (v.getId()) {
		case R.id.add_data:
			Uri uri = Uri.parse("content://com.example.databasetest.provider/book");
			ContentValues values = new ContentValues();
			values.put("name", "A Clash of Kings");
			values.put("author", "George Martin");
            values.put("pages", 1040);
            values.put("price", 22.85);
            Uri newUri = this.getContentResolver().insert(uri, values);
            newId = newUri.getPathSegments().get(1);
			break;
		case R.id.query_data:
			uri = Uri.parse("content://com.example.databasetest.provider/book");
			Cursor cursor = this.getContentResolver().query(uri, null, null, null, null);
			if (null != cursor) {
				while (cursor.moveToNext()) {
					String name = cursor.getString(cursor.getColumnIndexOrThrow("name"));
					String author = cursor.getString(cursor.getColumnIndexOrThrow("author"));
					int pages = cursor.getInt(cursor.getColumnIndexOrThrow("pages"));
					double price = cursor.getDouble(cursor.getColumnIndexOrThrow("price"));
					
					Log.d(TAG, "name >> " + name);
					Log.d(TAG, "author >> " + author);
					Log.d(TAG, "pages >> " + pages);
					Log.d(TAG, "price >> " + price);
				}
				cursor.close();
			}
			break;
		case R.id.update_data:
			uri = Uri.parse("content://com.example.databasetest.provider/book/" + newId);
			ContentValues values2 = new ContentValues();
            values2.put("name", "A Storm of Swords");
            values2.put("pages", 1216);
            values2.put("price", 24.05);
            this.getContentResolver().update(uri, values2, null, null);
			break;
		case R.id.delete_data:
			uri = Uri.parse("content://com.example.databasetest.provider/book/" + newId);
			this.getContentResolver().delete(uri, null, null);
			break;
		default:
			break;
		}

	}
}
