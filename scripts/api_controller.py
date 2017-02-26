# ROS
import rospy
from std_msgs.msg import String

# Web Server
import string, cgi, time
from os import curdir, sep
from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer

# This should be moved to a post later but it is a get for now to make the initial writing faster
# Change the message type when the type gets figured out

class handler(BaseHTTPRequestHandler):
    def do_get(self):
        path = path.split("/")
        # print x, y, z, theta, time
        x = path[1]
        y = path[2]
        z = path[3]
        roll = path[4]
        pitch = path[5]
        time = path[6]

        if path.contains("jacobian"):
            pub = rospy.Publisher("jCoordinates", String, queue_size=10)
        elif path.contains("ik"):
            pub = rospy.Publisher("ikCoordinates", String, queue_size=10)

        rospy.init_node("api_controller", anonymous=True)
        msg = "message"
        pub.publish(msg)

        self.send_response(200)
        return

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
