import os
import json
import datetime
from dotenv import load_dotenv
from flask import Flask, render_template, request
from flask_restful import Api, Resource
from flask_socketio import SocketIO, emit

load_dotenv()

app = Flask(__name__)
app.config['SECRET_KEY'] = os.environ.get('SECRET_KEY')
# Load SocketIO
socketio = SocketIO(app)
# Load Flask Restful
api = Api(app)

@app.route('/')
def index():
    return render_template('index.html')


class update_table_data(Resource):
    def post(self):
        value = request.form['value']
        datetime_ = datetime.datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S')
        data = {'datetime': str(datetime_), 'value':value}
        json_data = json.dumps(data)
        # Emit the render_data event
        socketio.emit('update_table', json_data)

        return True

api.add_resource(update_table_data, '/update/')

# app.route('/update')
# def update():
#     """
#     params data: a json string
#     """
#     datetime_ = request.form.get('datetime') # Or get datatime with python
#     datetime_ = datetime.datetime().utcnow()
#     value = request.form.get('value')
    
#     data = {'datetime': str(datetime_), 'value':value}
#     json_data = json.dumps(data)
#     # Emit the render_data event
#     emit('update_table', json_data)

# Logic
# Receive data from ESP32 through socket
# Pass the data to the template through socket
# 

if __name__ == "__main__":
    socketio.run(app, debug = True)