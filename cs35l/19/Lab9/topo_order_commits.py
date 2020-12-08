import os
import sys
import zlib
'''
Class: CommitNode
helper functions: 
    1. topo_order_commits
    2. dfs (depth first search)
    3. t_sort (topo sort)
    4. find_git
    5. find_branches
    6. find_commits
    7. parent (find par. from hash)
'''
# class definition
class CommitNode:
    def __init__(self, commit_hash, branches=[]):
        """
        :type commit_hash: str
        :type branches: set
        """
        self.commit_hash = commit_hash
        self.branches = branches
        self.parents = set()
        self.children = set()

    def __str__(self):
        return 'commit_hash: {self.commit_hash}, branches: {self.branches}'.format(self=self)

    def __repr__(self):
        return 'CommitNode<commit_hash: {self.commit_hash}, branches: {self.branches}>'.format(self=self)


# helper functions:
def topo_order_commits():
    # get top level git path
    path = find_git()
    path = path + "/.git/"

    # get information about branches
    branch_meta = find_branches(path)

    # get the information about commits and root_commits
    commit_meta, root_commits = find_commits(path, branch_meta)

    # sort the commits
    s_commits = t_sort(commit_meta, root_commits)

    # print output
    s_start = False
    for i in range(len(s_commits)):
        cur = s_commits[i]
        if i < (len(s_commits) - 1):
            next_com = s_commits[i+1]

        # check for sticky start
        if s_start:
            print("=", end="")
            print_val = commit_meta[cur].children
            print(*print_val)
            s_start = False

        # print branch name
        # and hash
        if len(commit_meta[cur].branches) == 0:
            print(cur)
        else:
            print(cur + " ", end="")
            print_val = sorted(commit_meta[cur].branches)
            print(*print_val)

        # check next commit if it is cur's parent
        # print out sticky end
        if next_com not in commit_meta[cur].parents and i < (len(s_commits) - 1):
            print_val = commit_meta[cur].parents
            print(*print_val, end="")
            print("=\n")
            s_start = True

def dfs(path, hash, commit_meta):
    root_commits = set()
    c_stack = [commit_meta[hash]]
    while len(c_stack) > 0:
        pop_val = c_stack.pop()
        pop_val.parents = parents(path, pop_val.commit_hash)
        if len(pop_val.parents) == 0:
            root_commits.add(pop_val.commit_hash)
            continue
        for p_hash in pop_val.parents:
            if commit_meta.get(p_hash) is not None:
                p_node = commit_meta[p_hash]
                p_node.children.add(pop_val.commit_hash)
                continue
            commit_meta[p_hash] = CommitNode(p_hash)
            p_node = commit_meta[p_hash]
            p_node.children.add(pop_val.commit_hash)
            c_stack.append(p_node)
    return root_commits


def t_sort(commit_meta, root_commits):
    out = list()
    seen_meta = dict()
    c_stack = list(root_commits.copy())
    while len(c_stack) > 0:
        top_val = c_stack[-1]
        seen_meta[top_val] = "seen" # record the footprint
        # find all children that have not been visited
        # this will loop through children aand check the seen_meta value to check if it has been seen
        cur_children = [child for child in commit_meta[top_val].children if seen_meta.get(child) is None]
        # if no unvisited children continue
        if len(cur_children) == 0:
            pop_val = c_stack.pop()
            out.append(pop_val)
            continue
        c_stack.append(cur_children[0])
    return out


# find .git dir
def find_git(d="."):
    while(os.path.abspath(d) != "/"):
        for dir in os.listdir(d):
            if os.path.isdir(os.path.join(d, dir)) and dir == ".git":
                return os.path.abspath(d)
        # else:
        d = "../" + d
    sys.stderr.write("Not inside a Git repository\n")
    sys.exit(1)


# get branch hash vals given .git
def find_branches(path):
    # find .git/refs/heads
    branch_path = path + "refs/heads/"
    # Meta of commit hash key and value of branch name
    branch_meta = dict()
    # check if branch_path is a directory
    if not os.path.isdir(branch_path):
        sys.stderr.write("pathrefs/heads/ is not a directory\n")
        sys.exit(1)

    for root, dirs, files in os.walk(branch_path):
        if files:
	        for f in files:
	            # open with flags read and binary
	            hash = open(os.path.join(root, f), 'rb').read().decode("latin-1")
	            hash = hash.strip('\n')
	            # if at the certain hash value it isn't initialized then initialize it
	            if branch_meta.get(hash) is None:
	                branch_meta[hash] = list()
	            # append the data
	            meta = os.path.join(root, f)[len(branch_path):]
	            branch_meta[hash].append(meta)
    return branch_meta


# get meta data for ComitNodes & the root_commits
def find_commits(path, branch_meta):
    obj_path = path + "objects/"
    commit_meta = dict()
    root_commits = set()
    for hash in branch_meta:
        if commit_meta.get(hash) is not None:
            commit_meta[hash].branches = branch_meta[hash]
            continue
        commit_meta[hash] = CommitNode(hash, branch_meta[hash])
        # use dfs 
        dfs_obj = dfs(obj_path, hash, commit_meta)
        root_commits = root_commits.union(dfs_obj)
    root_commits = sorted(root_commits)
    return commit_meta, root_commits


    
def parents(obj_path, hash):
    # because first two chars in hash are the folder name
    path = obj_path + hash[:2] + "/" + hash[2:]
    parent_set = set()
    if not os.path.isfile(path):
        sys.stderr.write("no object for hash: " + hash + "\n")
        sys.exit(1)
    obj = open(path, 'rb').read()
    obj = zlib.decompress(obj).decode("latin-1")
    obj = obj.replace("\n", " ")

    obj_meta = obj.split(" ")

    # loop through till you find "author"
    i = 0
    while obj_meta[i] != "author" and i < len(obj_meta):
        if obj_meta[i-1] == "parent":
            parent_set.add(obj_meta[i])
        i += 1
    # sort so that it will always give same result
    parent_set = sorted(parent_set)
    return parent_set

# === === === 
# MAIN
if __name__ == '__main__':
    topo_order_commits()