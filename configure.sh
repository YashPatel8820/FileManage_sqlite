
#!/bin/bash
echo "Initializing project configuration..."
echo "Creating database file if it doesn't exist"
sqlite3 users.db "CREATE TABLE IF NOT EXISTS USERS(ID INTEGER PRIMARY KEY AUTOINCREMENT, USERNAME TEXT NOT NULL, PASSWORD TEXT NOT NULL);"
echo "Configuration complete!"
