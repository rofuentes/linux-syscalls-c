variable "do_token"{
    string = "1"
}

provider "digitalocean" {
    token = "${var.do_token}"
}

resource "digitalocean_droplet" "linux-syscalls" {
    image = "ubuntu-16-04-x64"
    name = "linux-syscalls"
    region = "sfo1"
    size = "512mb"
}
