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
    def do_get(self):
        path = path.split("/")
        # print x, y, z, theta, time
        x = path[0]
        y = path[1]
        z = path[2]
        roll = path[3]
        pitch = path[4]
        hand = path[5]
        time = path[6]

        ikPub = rospy.Publisher("moveto", Target, queue_size=10)
        handPub = rospy.Publisher("handDriver", HandPos, queue_size=10)

        rospy.init_node("api_controller", anonymous=True)
        msg = Target(x, y, z, roll, pitch, time)
        ikPub.publish(msg)

        msg = HandPos(hand, time)
        handPub.publish(msg)

        self.send_response(200)
        return

    # Not in current use.
    def do_post(self):
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
    try:
        server = HTTPServer(("", 80), handler)
        # ros print "Server started..."
        server.serve_forever()
    except:
        # ros print "Shutting down server"
        server.socket.close()

if __name__ == "__main__":
    main()
