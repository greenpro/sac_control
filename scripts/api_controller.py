#!/usr/bin/env python

# NOTE :: the top line is not a comment it is necessary for ROS.
# ROS
import rospy
from std_msgs.msg import String
from sac_msgs.msg import Path
from sac_msgs.msg import Target
from sac_msgs.msg import HandPos

# Web Server
import string, cgi, time
from os import curdir, sep
from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer

# This should be moved to a post later but it is a get for now to make the initial writing faster
# Change the message type when the type gets figured out

# NOTE :: This code is not my own, It can be found at several sources here is one: pymotw.com/2/BaseHTTPServer

class handler(BaseHTTPRequestHandler):
    def do_GET(self):
        path = self.path.split("/")
        # print x, y, z, theta, time
        x = float(path[1])
        y = float(path[2])
        z = float(path[3])
        roll = float(path[4])
        pitch = float(path[5])
        hand = float(path[6])
        time = float(path[7])

	print("")
	print("x", x)
	print("y", y)
	print("z", z)
	print("r", roll)
	print("p", pitch)
	print("h", hand)
	print("t", time)
	print("")

        ikPub = rospy.Publisher("moveto", Target, queue_size=10)
        handPub = rospy.Publisher("handDriver", HandPos, queue_size=10)

        msg = Target(x, y, z, roll, pitch, time)
        ikPub.publish(msg)

        msg = HandPos(hand, time)
        handPub.publish(msg)

        self.send_response(200)
        return

    # Not in current use.
    def do_POST(self):
        global rootnode
        try:
            ctype, pdict = cgi.parse_header(self.headers.getheader("content-type"))
            if ctype == "multipart/form-data":
                query = cgi.parse_multipart(self.rfile, pdict)
            self.send_response(301)

            self.end_headers()
            upfilecontent = query.get("upfile")
            # print coordinates
            self.wfile.write("<HTML>POST OK.<BR><BR>");
            self.wfile.write(upfilecontent[0]);

        except:
            pass

def main():
    rospy.init_node("api_controller", anonymous=True)

    try:
	print("1");
        server = HTTPServer(("", 8080), handler)
	print("2");
        server.serve_forever()
	print("3");
    except:
	if 'server' in locals():
            server.socket.close()

if __name__ == "__main__":
    main()
