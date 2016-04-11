package com.example.databasetest;

import com.example.model.MyDatabaseHelper;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener {

	private MyDatabaseHelper dbHelper;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		dbHelper = new MyDatabaseHelper(this, "BookStore.db", null, 3);
		Button createDatabase = (Button) this.findViewById(R.id.create_table);
		createDatabase.setOnClickListener(this);
		Button addData = (Button) this.findViewById(R.id.add_data);
		addData.setOnClickListener(this);
		Button updateData = (Button) this.findViewById(R.id.update_data);
		updateData.setOnClickListener(this);
		Button deleteData = (Button) this.findViewById(R.id.delete_data);
		deleteData.setOnClickListener(this);
		Button selectData = (Button) this.findViewById(R.id.select_data);
		selectData.setOnClickListener(this);
		Button replaceData = (Button) this.findViewById(R.id.replace_data);
		replaceData.setOnClickListener(this);
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
		case R.id.create_table:
			dbHelper.getWritableDatabase();
			break;
		case R.id.add_data:
			SQLiteDatabase db = dbHelper.getWritableDatabase();
			ContentValues values = new ContentValues();
			values.put("name", "The Da Vinci Code");
			values.put("author", "Dan Brown");
			values.put("pages", 454);
			values.put("price", 16.96);
			db.insert("BOOK", null, values);
			values.clear();
			values.put("name", "The Lost Symbol");
			values.put("author", "Dan Brown");
			values.put("pages", 510);
			values.put("price", 19.95);
			db.insert("Book", null, values);
			break;
		case R.id.update_data:
			SQLiteDatabase db1 = dbHelper.getWritableDatabase();
			ContentValues values1 = new ContentValues();
			values1.put("price", 10.99);
			db1.update("Book", values1, "name=?", new String[] {"The Da Vinci Code"});
			break;
		case R.id.delete_data:
			SQLiteDatabase db2 = dbHelper.getWritableDatabase();
			db2.delete("Book", "pages > ?", new String[] {"500"});
			break;
		case R.id.select_data:
			SQLiteDatabase db3 = dbHelper.getWritableDatabase();
			Cursor cursor = db3.query("Book", null, null, null, null, null, null);
			if (cursor.moveToFirst()) {
				do {
					String name = cursor.getString(cursor.getColumnIndexOrThrow("name"));
					String author = cursor.getString(cursor.getColumnIndexOrThrow("author"));
					int pages = cursor.getInt(cursor.getColumnIndexOrThrow("pages"));
					double price = cursor.getDouble(cursor.getColumnIndexOrThrow("price"));
					Log.d("MainActivity", "name >> " + name);
					Log.d("MainActivity", "author >> " + author);
					Log.d("MainActivity", "pages >> " + pages);
					Log.d("MainActivity", "price >> " + price);
				} while (cursor.moveToNext());
			}
			cursor.close();
			break;
		case R.id.replace_data:
			SQLiteDatabase db4 = dbHelper.getWritableDatabase();
			db4.beginTransaction();
			try {
				db4.delete("Book", null, null);
//				if (true) {
//					throw new NullPointerException();
//				}
				ContentValues values4 = new ContentValues();
				values4.put("name", "Game of Thrones");
				values4.put("author", "George Martin");
				values4.put("pages", 720);
				values4.put("price", 20.85);
				db4.insert("Book", null, values4);
				db4.setTransactionSuccessful();
			} catch (Exception e) {
				e.printStackTrace();
			} finally {
				db4.endTransaction();
			}
			break;
		default:
			break;
		}

	}
}
