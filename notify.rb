#!/usr/bin/env ruby
require 'rubygems'
require 'serialport'
require 'json'
require 'net/http'
require 'bigdecimal'
require 'optparse'
require 'gmail'
require 'yaml'

def read_config
  config = YAML.load_file("/home/mafi/.notify.conf")
  @username_gmail = config["gmail"]["username"]
  @password_gmail = config["gmail"]["password"]
end


read_config()


@options = {}

opt_parser = OptionParser.new do |opt|
  opt.banner = "Usage: notify.rb SERIALPORT [OPTIONS]"
  opt.separator  ""
  opt.separator  "Example:"
  opt.separator  "     ./notify.rb /dev/ttyACM0"
  opt.separator  ""
  opt.separator  "Options"

  opt.on("-c","--console","Console output?") do
    @options[:console] = true
  end

  opt.on("-h","--help","help") do
    puts opt_parser
  end
end

opt_parser.parse!

if ARGV[0] == nil
  puts "Specifiy port"
  puts opt_parser
  exit 1
end

@port = SerialPort.new(ARGV[0], 9600)

def check_usd(usd)
  if usd < @usd_old
    return 'red'
  else
    return 'green'
  end
end

def check_eur(eur)
  if eur < @eur_old
    return 'red'
  else
    return 'green'
  end
end

def get_mtgox_usd
  responseusd =  Net::HTTP.get('data.mtgox.com', '/api/1/BTCUSD/ticker')
  parsedusd = JSON.parse(responseusd)
  usd = parsedusd["return"]["last_local"]["value"].to_f
end

def get_mtgox_eur
  responseeur =  Net::HTTP.get('data.mtgox.com', '/api/1/BTCEUR/ticker')
  parsedeur = JSON.parse(responseeur)
  eur = parsedeur["return"]["last_local"]["value"].to_f
end

def get_gmail_count
  @gmail.inbox.count(:unread)
end

def open_sessions
  @gmail = Gmail.new(@username_gmail, @password_gmail)
end

def close_sessions
  @gmail.logout
end

def bitcoin_page
   usd = get_mtgox_usd
   eur = get_mtgox_eur
   @usd_old = usd
   @eur_old = eur
   serial_string = "f=normal\n" + "c=orange\n" + "w=0001:A\n" + "w=0008:B\n" +
                   "c=#{check_usd(usd)}\n" + "f=small\n" +
                   "W=2600:#{('%.2f' % usd).to_s.reverse!}\n" +
                   "c=#{check_eur(eur)}\n" +
                   "W=2607:#{('%.2f' % eur).to_s.reverse!}\n" +
                   "C=\n"
   @port.puts serial_string
end

def gmail_page
  serial_string = "f=normal\n" + "c=red\n" + "w=0001:gmail\n" +
                  "w=1009:#{get_gmail_count}\n" + "C=\n"
   @port.puts serial_string
end

def next_page
  serial_string = "N=\n"
  @port.puts serial_string
end

@usd_old = 0.0;
@eur_old = 0.0;

begin
  open_sessions
loop {

  bitcoin_page
  sleep 10
  gmail_page
  sleep 10

  if @options[:console] == true
    puts "#{get_mtgox_usd} Dollar"
    puts "#{get_mtgox_eur} Euro"
    puts "#{get_gmail_count} Gmail"
  end
}
rescue Exception => e
  close_sessions
end
